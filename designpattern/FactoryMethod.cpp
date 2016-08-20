#include <iostream>
#include <vector>

using namespace std;

#ifdef BEFORE
class Stooge
{
    public:
        virtual void slap_stick() = 0;
        virtual ~Stooge() {}
};

class Larry: public Stooge
{
    public:
        void slap_stick()
        {
            cout << "Larry: poke eyes" << endl;
        }
};

class Moe: public Stooge
{
    public:
        void slap_stick()
        {
            cout << "Moe: slap head" << endl;
        }
};

class Curly: public Stooge
{
    public:
        void slap_stick()
        {
            cout << "Curly: suffer abuse" << endl;
        }
};

int main()
{
    vector<Stooge *> roles;
    int choice;

    while (true)
    {
        cout << "Larry(1) Moe(2) Curly(3) Go(0): ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        switch (choice) {
            case 1:
                {
                    roles.push_back(new Larry);
                    break;
                }
            case 2:
                {
                    roles.push_back(new Moe);
                    break;
                }
            case 3:
                {
                    roles.push_back(new Curly);
                    break;
                }
        }
    }

    for (auto &a: roles)
    {
        a->slap_stick();
    }

    for (auto &a: roles)
    {
        delete a;
    }
}
#endif

#ifdef AFTER
class Stooge
{
    public:
        static Stooge *make_stooge(int choice);
        virtual void slap_stick() = 0;
        virtual ~Stooge() {}
};

int main()
{
    vector<Stooge *> roles;
    int choice;

    while (true)
    {
        cout << "Larry(1) Moe(2) Curly(3) Go(0): ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        roles.push_back(Stooge::make_stooge(choice));
    }

    for (auto &a: roles)
    {
        a->slap_stick();
    }

    for (auto &a: roles)
    {
        delete a;
    }
}

class Larry: public Stooge
{
    public:
        void slap_stick()
        {
            cout << "Larry: poke eyes";
        }
};

class Moe: public Stooge
{
    public:
        void slap_stick()
        {
            cout << "Moe: slap head";
        }
};

class Curly: public Stooge
{
    public:
        void slap_stick()
        {
            cout << "Curly: suffer abuse";
        }
};

Stooge *Stooge::make_stooge(int choice)
{
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

#ifdef NORMAL
class Document
{
    public:
        Document(const string &fn): name(fn)
        {
        }

        virtual void Open() = 0;
        virtual void Close() = 0;
        string GetName()
        {
            return name;
        }
    private:
        string name;
};

class MyDocument: public Document
{
    public:
        MyDocument(const string &fn): Document(fn) {}
        void Open()
        {
            cout << "    MyDocument: Open()" << endl;
        }

        void Close()
        {
            cout << "    MyDocument: Close()" << endl;
        }
};

class Application
{
    public:
        Application(): _index(0)
        {
            cout << "Application: ctor" << endl;
        }

        void NewDocument(const string &name)
        {
            cout << "Application: NewDocument()" << endl;
            _docs[_index] = CreateDocument(name);
            _docs[_index++]->Open();
        }

        void OpenDocument() {}
        void ReportDocs();

        virtual Document *CreateDocument(const string &) = 0;
    private:
        int _index;
        Document *_docs[10];
};

void Application::ReportDocs()
{
    cout << "Application: ReportDocs()" << endl;

    for (int i = 0; i < _index; ++i) {
        cout << "    " << _docs[i]->GetName() << endl;
    }
}

class MyApplication: public Application
{
    public:
        MyApplication()
        {
            cout << "MyApplication: ctor" << endl;
        }

        Document *CreateDocument(const string &fn)
        {
            cout << "    MyApplication: CreateDocument()" << endl;
            return new MyDocument(fn);
        }
};

int main()
{
    MyApplication myApp;

    myApp.NewDocument("foo");
    myApp.NewDocument("bar");
    myApp.ReportDocs();
}
#endif
