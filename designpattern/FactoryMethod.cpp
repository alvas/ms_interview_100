#include <iostream>
#include <vector>

using namespace std;

#ifdef NORMAL
class Document {
    public:
        Document(const string &fn): name(fn) { }

        virtual void Open() = 0;
        virtual void Close() = 0;
        virtual ~Document() {}

        string GetName() {
            return name;
        }

    private:
        string name;
};

class MyDocument: public Document {
    public:
        MyDocument(const string &fn): Document(fn) {}
        void Open() {
            cout << "    MyDocument: Open()" << endl;
        }

        void Close() {
            cout << "    MyDocument: Close()" << endl;
        }
};

class Application {
    public:
        Application() {
            cout << "Application: ctor" << endl;
        }

        void NewDocument(const string &name) {
            cout << "Application: NewDocument()" << endl;
            _docs.push_back(shared_ptr<Document>(CreateDocument(name)));
            _docs.back()->Open();
        }

        void OpenDocument() {}
        void ReportDocs();

        virtual Document *CreateDocument(const string &) = 0;
    private:
        // Document is a virtual base class, we can't use vector<Document> _docs,
        // because we can't allocate an object of abstract class type Document
        vector<shared_ptr<Document>> _docs;
};

void Application::ReportDocs() {
    cout << "Application: ReportDocs()" << endl;

    for (auto &a: _docs) {
        cout << "    " << a->GetName() << endl;
    }
}

class MyApplication: public Application {
    public:
        MyApplication() {
            cout << "MyApplication: ctor" << endl;
        }

        Document *CreateDocument(const string &fn) {
            cout << "    MyApplication: CreateDocument()" << endl;
            return new MyDocument(fn);
        }
};

int main() {
    MyApplication myApp;
    myApp.NewDocument("foo");
    myApp.NewDocument("bar");
    myApp.ReportDocs();
}
#endif

#ifdef BEFORE
class Stooge {
    public:
        virtual void slap_stick() = 0;
        virtual ~Stooge() {}
};

class Larry: public Stooge {
    public:
        void slap_stick() {
            cout << "Larry: poke eyes" << endl;
        }
};

class Moe: public Stooge {
    public:
        void slap_stick() {
            cout << "Moe: slap head" << endl;
        }
};

class Curly: public Stooge {
    public:
        void slap_stick() {
            cout << "Curly: suffer abuse" << endl;
        }
};

int main() {
    vector<shared_ptr<Stooge>> roles;
    int choice;

    while (true) {
        cout << "Larry(1) Moe(2) Curly(3) Go(0): ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        switch (choice) {
            case 1:
                {
                    roles.push_back(shared_ptr<Stooge>(new Larry));
                    break;
                }
            case 2:
                {
                    roles.push_back(shared_ptr<Stooge>(new Moe));
                    break;
                }
            case 3:
                {
                    roles.push_back(shared_ptr<Stooge>(new Curly));
                    break;
                }
        }
    }

    for (auto &a: roles) {
        a->slap_stick();
    }
}
#endif

#ifdef AFTER
class Stooge {
    public:
        static Stooge *make_stooge(int choice);
        virtual void slap_stick() = 0;
        virtual ~Stooge() {}
};

int main() {
    vector<shared_ptr<Stooge>> roles;
    int choice;

    while (true) {
        cout << "Larry(1) Moe(2) Curly(3) Go(0): ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        roles.push_back(shared_ptr<Stooge>(Stooge::make_stooge(choice)));
    }

    for (auto &a: roles) {
        a->slap_stick();
    }
}

class Larry: public Stooge {
    public:
        void slap_stick() {
            cout << "Larry: poke eyes";
        }
};

class Moe: public Stooge {
    public:
        void slap_stick() {
            cout << "Moe: slap head";
        }
};

class Curly: public Stooge {
    public:
        void slap_stick() {
            cout << "Curly: suffer abuse";
        }
};

Stooge *Stooge::make_stooge(int choice) {
    if (choice == 1) {
        return new Larry;
    }
    else if (choice == 2) {
        return new Moe;
    }
    else {
        return new Curly;
    }
}
#endif
