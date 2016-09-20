#include <iostream>

using namespace std;

#ifdef NORMAL
class Icon {
    public:
        Icon(char* fileName) {
            strcpy(_name, fileName);

            if (!strcmp(fileName, "go")) {
                _width = 20;
                _height = 20;
            }

            if (!strcmp(fileName, "stop")) {
                _width = 40;
                _height = 40;
            }

            if (!strcmp(fileNName, "select")) {
                _width = 60;
                _height = 60
            }

            if (!strcmp(fileNName, "undo")) {
                _width = 30;
                _height = 30
            }
        }

        const char* getName() {
            return _name;
        }

        draw(int x, int y) {
            cout << "    drawing " << _name << ": upper left (" << x << "," << y << ") - lower right (" << x + _width << "," << y + _height << ")" << endl;
        }

    private:
        char _name[20];
        int _width;
        int _height;
}

class FlyweightFactory {
    public:
        static Icon* getIcon(char* name) {
            for (int i = 0; i < _numIcons; ++i) {
                if (!strcmp(name, _icons[i]->getName())) {
                    return _icons[i];
                }
            }

            _icons[_numIcons] = new Icon(name);
            return _icons[_numIcons++];
        }

        static void reportTheIcons() {
            cout << "Active Flyweights: ";

            for (int i = 0; i < _numIcons; ++i) {
                cout << _icons[i]->getName() << " ";
            }

            cout << endl;
        }

    private:
        enum {
            MAX_ICONS = 5
        };

        static int _numIcons;
        static Icon* icons[MAX_ICONS];
};

int FlyweightFactory::_numIcons = 0;
Icon* FlyweightFactory::_icons[];

class DialogBos {
    public:
        DialogBox(int x, int y, int incr): _iconsOriginX(x), _iconsOriginY(y), _iconsXIncrement(incr) {}
        virtual void draw() = 0;

    protected:
        Icons* _icons[3];
        int _iconsOriginX;
        int _iconsOriginY;
        int _iconsXIncrement;
};

class FileSelection: public DialogBox {
    public:
        FileSelection(Icon* first, Icons* second, Icons* third) : DialogBox(100, 100, 100) {
            _icons[0] = first;
            _icons[1] = second;
            _icons[2] = third;
        }

        void draw() {
            cout << "drawing FileSelection:" << endl;

            for (int i = 0; i < 3; ++i) {
                _icons[i]->draw(_iconsOriginX + (i * _iconsXIncrement), _iconsOriginY);
            }
        }
};

class CommitTransaction: public DialogBox {
    public:
        CommitTransaction(Icons* first, Icon* second, Icon* third): DialogBox(150, 150, 150) {
            _icons[0] = first;
            _icons[1] = second;
            _icons[2] = third;
        }

        void draw() {
            cout << "drawing CommitTransaction:" << endl;

            for (int i = 0; i < 3; ++i) {
                _icons[i]->draw(_iconsOriginX + (i * _iconsXIncrement), _iconsOriginY);
        }
}

int main() {
    DialogBox* dialogs[2];

    dialog[0] = new FileSelection(FlyweightFactory::getIcon("go"), FlyweightFactor::getIcon("stop"), FlyweightFactory::getIcon("select"));
    dialog[1] = new CommitTransaction(FlyweightFactory::getIcon("select"), FlyweightFactor::getIcon("stop"), FlyweightFactory::getIcon("undo"));

    for (int i = 0; i < 2; ++i) {
        dialogs[i]->draw();
    }

    FlyweightFactor::reportTheIcons();
    return 0;
}
#endif

#ifdef BEFORE
class Gazillion {
    public:
        Gazillion() {
            m_value_one = s_num / Y;
            m_value_two = s_num % Y;
            ++s_num;
        }

        void report() {
            cout << m_value_one << m_value_two << ' ';
        }

        static int X, Y;

    private:
        int m_value_one;
        int m_value_two;
        static int s_num;
};

int Gazillion::X = 6, Gazillion::Y = 10, Gazillion::s_num = 0;

int main() {
    Gazillion matrix[Gazillion::X][Gazillion::Y];

    for (int i = 0; i < Gazillion::X; ++i) {
        for (int j = 0; j < Gazillion::Y; ++j) {
            matrix[i][j].report();
        }

        cout << endl;
    }

    return 0;
}
#endif

#ifdef AFTER
class Gazillion {
    public:
        Gazzilion(int value_one) {
            m_value_one = value_one;
            cout << "ctor: " << m_value_one << endl;
        }

        ~Gazzilion() {
            cout << m_value_one << ' ';
        }

        void report(int value_two) {
            cout << m_value_one << value_two << ' ';
        }

    private:
        int m_value_one;
};

class Factory {
    public:
        static Gazillion *get_fly(int in) {
            if (!s_pool[in]) {
                s_pool[in] = new Gazillion(in);
            }

            return s_pool[in];
        }

        static void clean_up() {
            cout << "dtors: ";

            for (int i = 0; i < X; ++i) {
                if (s_pool[i]) {
                    delete s_pool[i];
                }
            }

            cout << endl;
        }

        static int X, Y;
    private:
        static Gazillion* s_pool[];
};

int Factory::X = 6, Factory::Y = 10;
Gazillion* Factory::s_pool[] = {
    0, 0, 0, 0, 0, 0
};

int main() {
    for (int i = 0; i < Factory::X; ++i) {
        for (int j = 0; j < Factory::Y; ++j) {
            Factory::get_fly(i)->report(j);
        }

        cout << endl;
    }

    Factory::clean_up();

    return 0;
}
#endif
