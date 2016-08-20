#include <iostream>
#include <string>

using namespace std;

#ifdef NORMAL
class Number {
    public:
        static Number *instance();

        static void setType(string t) {
            type = t;
            delete inst;
            inst = 0;
        }

        virtual void setValue(int in) {
            value = in;
        }

        virtual int getValue() {
            return value;
        }

    protected:
        int value;

        Number() {
            cout << ":ctor: ";
        }

    private:
        static string type;
        static Number* inst;
};

string Number::type = "decimal";
Number* Number::inst = 0;

class Octal: public  Number {
    public:
        friend class Number;

        void setValue(int in) {
            char buf[10];
            sprintf(buf, "%o", in);
            sscanf(buf, "%d", &value);
        }

    protected:
        Octal() {}
};

Number* Number::instance() {
    if (!inst) {
        if (type == "octal") {
            inst = new Octal();
        }
        else {
            inst = new Number();
        }
    }

    return inst;
}

int main() {
    Number::instance()->setValue(42);
    cout << "value is " << Number::instance()->getValue() << endl;
    Number::setType("octal");
    Number::instance()->setValue(64);
    cout << "value is " << Number::instance()->getValue() << endl;
}
#endif

#ifdef BEFORE
class GlobalClass {
    int m_value;

    public:
    GlobalClass(int v = 0) {
        m_value = v;
    }

    int get_value() {
        return m_value;
    }

    void set_value(int v) {
        m_value = v;
    }
};

GlobalClass* global_ptr = 0;

void foo() {
    if (!global_ptr) {
        global_ptr = new GlobalClass;
    }

    global_ptr->set_value(1);
    cout << "foo: global_ptr is " << global_ptr->get_value() << endl;
}

void bar() {
    if (!global_ptr) {
        global_ptr = new GlobalClass;
    }

    global_ptr->set_value(2);
    cout << "bar: global_ptr is " << global_ptr->get_value() << endl;
}

int main() {
    if (!global_ptr) {
        global_ptr = new GlobalClass;
    }

    cout << "main: global_ptr is " << global_ptr->get_value() << endl;
    foo();
    bar();
}
#endif

#ifdef AFTER
class GlobalClass {
    int m_value;
    static GlobalClass* s_instance;
    
    GlobalClass(int v = 0) {
        m_value = v;
    }

    public:
    int get_value() {
        return m_value;
    }

    void set_value(int v) {
        m_value = v;
    }

    static GlobalClass *instance() {
        if (!s_instance) {
            s_instance = new GlobalClass;
        }

        return s_instance;
    }
};

GlobalClass* GlobalClass::s_instance = 0;

void foo() {
    GlobalClass::instance()->set_value(1);
    cout << "foo: global_ptr is " << GlobalClass::instance()->get_value() << endl;
}

void bar() {
    GlobalClass::instance()->set_value(2);
    cout << "bar: global_ptr is " << GlobalClass::instance()->get_value() << endl;
}

int main() {
    cout << "main: global_ptr is " << GlobalClass::instance()->get_value() << endl;
    foo();
    bar();
}
#endif
