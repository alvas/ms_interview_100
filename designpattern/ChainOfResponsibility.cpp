#include <iostream>
#include <vector>

using namespace std;

#ifdef COMPONENT
class Component {
    int value;
    Component *next;

    public:
    Component(int v, Component *n) {
        value = v;
        next = n;
    }

    void setNext(Component *n) {
        next = n;
    }

    virtual void traverse() {
        cout << value << ' ';
    }

    virtual void volunteer() {
        next->volunteer();
    }
};

class Primitive: public Component {
    public:
        Primitive(int val, Component *n = nullptr): Component(val, n) {}

        void volunteer() {
            Component::traverse();

            if (rand() * 100 % 6 != 0) {
                Component::volunteer();
            }
        }
};

class Composite: public Component {
    vector<Component*> children;
    
    public:
    Composite(int val, Component *n = nullptr): Component(val, n) {}

    void add(Component* c) {
        children.push_back(c);
    }

    void traverse() {
        Component::traverse();

        for (int i = 0; i < children.size(); ++i) {
            children[i]->traverse();
        }
    }

    void volunteer() {
        Component::volunteer();
    }
};

int main() {
    srand(time(0));
    Primitive seven(7);
    Primitive six(6, &seven);
    Composite three(3, &six);
    three.add(&six);
    three.add(&seven);
    Primitive five(5, &three);
    Primitive four(4, &five);
    Composite two(2, &four);
    two.add(&four);
    two.add(&five);
    Composite one(1, &two);
    Primitive nine(9, &one);
    Primitive eight(8, &nine);
    one.add(&two);
    one.add(&three);
    one.add(&eight);
    one.add(&nine);
    seven.setNext(&eight);
    cout << "traverse: ";
    one.traverse();
    cout << endl;

    for (int i = 0; i < 8; ++i) {
        one.volunteer();
        cout << endl;
    }
}
#endif

#ifdef NORMAL
class Base {
    Base *next;

    public:
    Base() {
        next = nullptr;
    }

    void setNext(Base *n) {
        next = n;
    }

    void add(Base *n) {
        if (next) {
            next->add(n);
        }
        else {
            next = n;
        }
    }

    virtual void handle(int i) {
        next->handle(i);
    }
};

class Handler1: public Base {
    public:
        void handle(int i) {
            if (rand() % 3) {
                cout << "H1 passed " << i << " ";
                Base::handle(i);
            }
            else {
                cout << "H1 handled " << i << " ";
            }
        }
};

class Handler2: public Base {
    public:
        void handle(int i) {
            if (rand() % 3) {
                cout << "H2 passed " << i << " ";
                Base::handle(i);
            }
            else {
                cout << "H2 handled " << i << " ";
            }
        }
};

class Handler3: public Base {
    public:
        void handle(int i) {
            if (rand() % 3) {
                cout << "H3 passed " << i << " ";
                Base::handle(i);
            }
            else {
                cout << "H3 handled " << i << " ";
            }
        }
};

int main() {
    srand(time(0));
    Handler1 root;
    Handler2 two;
    Handler3 thr;
    root.add(&two);
    root.add(&thr);
    thr.setNext(&root);

    for (int i = 1; i < 10; ++i) {
        root.handle(i);
        cout << endl;
    }
}
#endif
