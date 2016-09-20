#include <iostream>
#include <string>

using namespace std;

#ifdef NORMAL
class Element {
    public:
        virtual void accept(class Visitor& v) = 0;
};

class This: public Element {
    public:
        void accept(Visitor& v);

        string thiss() {
            return "This";
        }
};

class That: public Element {
    public:
        void accept(Visitor& v);

        string that() {
            return "That";
        }
};

class TheOther: public Element {
    public:
        void accept(Visitor& v);

        string theOther() {
            return "TheOther";
        }
};

class Visitor {
    public:
        virtual void visit(This* e) = 0;
        virtual void visit(That* e) = 0;
        virtual void visit(TheOther* e) = 0;
};

void This::accept(Visitor& v) {
    v.visit(this);
}

void That::accept(Visitor& v) {
    v.visit(this);
}

void TheOther::accept(Visitor& v) {
    v.visit(this);
}

class UpVisitor: public Visitor {
    void visit(This* e) {
        cout << "do Up on " + e->thiss() << endl;
    }

    void visit(That* e) {
        cout << "do Up on " + e->that() << endl;
    }

    void visit(TheOther *e) {
        cout << "do Up on " + e->theOther() << endl;
    }
}

class DownVisitor: public Visitor {
    void visit(This* e) {
        cout << "do Down on " + e->thiss() << endl;
    }

    void visit(That* e) {
        cout << "do Down on " + e->that() << endl;
    }

    void visit(TheOther* e) {
        cout << "do Down on " + e->theOther() << endl;
    }
};

int main() {
    Element* list[] = {
        new This(), new That(), new TheOther()
    };

    UpVisitor up;
    DownVisitor down;

    for (int i = 0; i < 3; ++i) {
        list[i]->accept(up);
    }

    for (int i = 0; i < 3; ++i) {
        list[i]->accept(down);
    }

    return 0;
}
#endif

#ifdef BEFORE
class Color {
    public:
        virtual void count() = 0;
        virtual void call() = 0;
        static void report_num() {
            cout << "Reds " << s_num_red << ", Blus " << s_num_blu << endl;
        }

    protected:
        static int s_num_red, s_num_blu;
};

int Color::s_num_red = 0;
int Color::s_num_blu = 0;

class Red: public Colr {
    public:
        void count() {
            ++s_num_red;
        }

        void call() {
            eye();
        }

        void eye() {
            cout << "Red::eye" << endl;
        }
};

class Blu: public Color {
    public:
        void count() {
            ++s_num_blu;
        }

        void call() {
            sky();
        }

        void sky() {
            cout << "Blu::sky" << endl;
        }
};

int main() {
    Color* set[] = {
        new Red, new Blu, new Blu, new Red, new Red, 0
    };

    for (int i = 0; set[i]; ++i) {
        set[i]->count();
        set[i]->call();
    }

    Color::report_num();
    return 0;
}
#endif

#ifdef AFTER
class Color {
    public:
        virtual void accept(class Visitor*) = 0;
};

class Red: public Color {
    public:
        void accept(Visitor*);
        
        void eye() {
            cout << "Red::eye" << endl;
        }
};

class Blu: public Color {
    public:
        void accept(Visitor*);

        void sky() {
            cout << "Blu::sky" << endl;
        }
};

class Visitor {
    public:
        virtual void visit(Red*) = 0;
        virtual void visit(Blu*) = 0;
};

class CountVisitor: public Visitor {
    public:
        CountVisitor() {
            m_num_red = m_num_blu = 0;
        }

        void visit(Red*) {
            ++m_num_red;
        }

        void visit(Blu*) {
            ++m_num_blu;
        }

        void report_num() {
            cout << "Reds " << m_num_red << ", Blus " << m_num_blu << endl;
        }

    private:
        int m_num_red, m_num_blu;
};

class CallVisitor: public Visitor {
    public:
        void visit(Red* r) {
            r->eye();
        }

        void visit(Blu* b) {
            b->sky();
        }
};

void Red::accept(Visitor* v) {
    v->visit(this);
}

void Blu::accept(Visitor* v) {
    v->visit(this);
}

int main() {
    Color* set[] = {
        new Red, new Blu, new Blu, new Red, new Red, 0
    };

    CountVisitor count_operation;
    CallVisitor call_operation;

    for (int i = 0; set[i]; ++i) {
        set[i]->accept(&count_operation);
        set[i]->accept(&call_operation);
    }

    count_operation.report_num();
    return 0;
}
#endif

#ifdef TYPE
class Visitor {
    public:
        virtual void visit(class Primitive*, class Component*) = 0;
        virtual void visit(class Composite*, Component*) = 0;
};

class Component {
    int value;

    public:
    Component(int val) {
        value = val;
    }

    virtual void traverse() {
        cout << value << " ";
    }

    virtual void accept(Visitor&, Component*) = 0;
};

class Primitive: public Component {
    public:
        Primitive(int val): Component(val) {}
        
        void accept(Visitor& v, Component* c) {
            v.visit(this, c);
        }
};

class Composite: public Component {
    vector<Component*> children;
    public:
    Compiste(int val): Component(val) {}

    void add(Component* ele) {
        children.push_back(ele);
    }

    void accept(Visitor& v, Component* c) {
        v.visit(this, c);
    }

    void traverse() {
        Component::traverse();
        
        for (int i = 0; i < children.size(); ++i) {
            children[i]->traverse();
        }
    }
};

class AddVisitor: public Visitor {
    public:
        void visit(Primitive*, Component*) {

        }

        void visit(Composite* node, Component* c) {
            node->add(c);
        }
};

int main() {
    Component* nodes[3];
    nodes[0] = new Composite(1);
    nodes[1] = new Composite(2);
    nodes[2] = new Composite(3);

    AddVisitor addVisitor;
    nodes[0]->accept(addVisitor, nodes[1]);
    nodes[0]->accept(addVisitor, nodes[2]);
    nodes[0]->accept(addVisitor, new Primitive(4));
    nodes[1]->accept(addVisitor, new Primitive(5));
    nodes[1]->accept(addVisitor, new Primitive(6));
    nodes[2]->accept(addVisitor, new Primitive(7));

    for (int i = 0; i < 3; ++i) {
        nodes[i]->traverse();
        cout << endl;
    }

    return 0;
}
#endif
