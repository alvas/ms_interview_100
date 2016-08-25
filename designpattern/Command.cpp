#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifdef NORMAL
class Person;

class Command {
    Person* object;
    void(Person::*method)();

    public:
    Command(Person* obj = nullptr, void(Person::*meth)() = nullptr) {
        object = obj;
        method = meth;
    }

    void execute() {
        (object->*method)();
    }
};

class Person {
    string name;
    Command cmd;

    public:
    Person(string n, Command c): cmd(c) {
        name = n;
    }

    void talk() {
        cout << name << " is talking" << endl;
        cmd.execute();
    }

    void passOn() {
        cout << name << " is passing on" << endl;
        cmd.execute();
    }

    void gossip() {
        cout << name << " is gossiping" << endl;
        cmd.execute();
    }

    void listen() {
        cout << name << " is listening" << endl;
    }
};

int main() {
    Person wilma("Wilma", Command());
    Person betty("Betty", Command(&wilma, &Person::listen));
    Person barney("Barney", Command(&betty, &Person::gossip));
    Person fred("Fred", Command(&barney, &Person::passOn));
    fred.talk();
    return 0;
}
#endif

#ifdef BEFORE
class Giant {
    public:
        enum Type {
            Fee, Phi, Pheaux
        };

        Giant () {
            m_id = s_next++;
            m_type = (Type)(m_id % 3);
        }

        Type get_type() {
            return m_type;
        }

        void fee() {
            cout << m_id << "-fee ";
        }

        void phi() {
            cout << m_id << "-phi ";
        }

        void pheaux() {
            cout << m_id << "-pheaux ";
        }

    private:
        Type m_type;
        int m_id;
        static int s_next;
};

int Giant::s_next = 0;

template<typename T> class Queue {
    public:
        Queue() {
            m_add = m_remove = 0;
        }

        void enque(T* c) {
            m_array[m_add] = c;
            m_add = (m_add + 1) % SIZE;
        }

        T* deque() {
            int temp = m_remove;
            m_remove = (m_remove + 1) % SIZE;
            return m_array[temp];
        }

    private:
        enum {
            SIZE = 8
        };

        T* m_array[SIZE];
        int m_add, m_remove;
};

int main() {
    Queue<Giant> que;
    Giant input[6], *bad_guy = nullptr;

    for (int i = 0; i < 6; ++i) {
        que.enque(&input[i]);
    }

    for (int i = 0; i < 6; ++i) {
        bad_guy = que.deque();

        if (bad_guy->get_type() == Giant::Fee) {
            bad_guy->fee();
        }
        else if (bad_guy->get_type() == Giant::Phi) {
            bad_guy->phi();
        }
        else if (bad_guy->get_type() == Giant::Pheaux) {
            bad_guy->pheaux();
        }
    }

    cout << endl;
}
#endif

#ifdef AFTER
class Giant {
    public:
        Giant() {
            m_id = s_next++;
        }

        void fee() {
            cout << m_id << "-fee ";
        }

        void phi() {
            cout << m_id << "-phi ";
        }

        void pheaux() {
            cout << m_id << "-pheaux ";
        }

    private:
        int m_id;
        static int s_next;
};

int Giant::s_next = 0;

class Command {
    public:
        typedef void(Giant::*Action)();
        Command(Giant* object, Action method) {
            m_object = object;
            m_method = method;
        }

        void execute() {
            (m_object->*m_method)();
        }

    private:
        Giant* m_object;
        Action m_method;
};

template<typename T> class Queue {
    public:
        Queue() {
            m_add = m_remove = 0;
        }

        void enque(T* c) {
            m_array[m_add] = c;
            m_add = (m_add + 1) % SIZE;
        }

        T* deque() {
            int temp = m_remove;
            m_remove = (m_remove + 1) % SIZE;
            return m_array[temp];
        }

    private:
        enum {
            SIZE = 8
        };

        T* m_array[SIZE];
        int m_add, m_remove;
};

int main() {
    Queue<Command> que;

    Command *input[] = {
        new Command(new Giant, &Giant::fee),
        new Command(new Giant, &Giant::phi),
        new Command(new Giant, &Giant::pheaux),
        new Command(new Giant, &Giant::fee),
        new Command(new Giant, &Giant::phi),
        new Command(new Giant, &Giant::pheaux)
    };

    for (int i = 0; i < 6; ++i) {
        que.enque(input[i]);
    }

    for (int i = 0; i < 6; ++i) {
        que.deque()->execute();
    }

    cout << endl;
}
#endif

#ifdef SIMPLE
class Number {
    public:
        void dubble(int &value) {
            value *= 2;
        }
};

class Command {
    public:
        virtual void execute(int &) = 0;
};

class SimpleCommand: public Command {
    typedef void(Number::*Action)(int &);
    Number *receiver;
    Action action;

    public:
    SimpleCommand(Number* rec, Action act) {
        receiver = rec;
        action = act;
    }

    void execute(int &num) {
        (receiver->*action)(num);
    }
};

class MacroCommand: public Command {
    vector<Command*> list;

    public:
    void add(Command* cmd) {
        list.push_back(cmd);
    }

    void execute(int &num) {
        for (int i = 0; i < list.size(); ++i) {
            list[i]->execute(num);
        }
    }
};

int main() {
    Number object;
    Command* commands[3];
    
    SimpleCommand one(&object, &Number::dubble);
    commands[0] = &one;

    MacroCommand two;
    two.add(commands[0]);
    two.add(commands[0]);
    commands[1] = &two;

    MacroCommand four;
    four.add(&two);
    four.add(&two);
    commands[2] = &four;

    int num = 0, index = 0;

    while (true) {
        cout << "Enter number selection (0=2x, 1=4x 2=16x): ";
        cin >> num >> index;
        commands[index]->execute(num);
        cout << "    " << num << endl;
    }
}
#endif
