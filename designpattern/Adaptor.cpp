#include <iostream>

using namespace std;

#ifdef NORMAL
typedef int Coordinate;
typedef int Dimension;

class Rectangle {
    public:
        virtual void draw() = 0;
};

class LegacyRectangle {
    public:
        LegacyRectangle(Coordinate x1, Coordinate y1, Coordinate x2, Coordinate y2) {
            x1_ = x1;
            y1_ = y1;
            x2_ = x2;
            y2_ = y2;
            cout << "LegacyRectangle: create. (" << x1_ << "," << y1_ << ") => (" << x2_ << "," << y2 << ")" << endl;
        }

        void oldDraw() {
            cout << "LegacyRectangle: oldDraw. (" << x1_ << "," << y1_ << ") = > (" << x2_ << "," << y2_ << ")" << endl;
        }

    private:
        Coordinate x1_;
        Coordinate x2_;
        Coordinate y1_;
        Coordinate y2_;
};

class RectangleAdapter: public Rectangle, private LegacyRectangle {
    public RectangleAdapter(Coordinate x, Coordinate y, Dimension w, Dimension h): LegacyRectangle(x, y, x + w, y + h) {
        cout << "RectangleAdapter: create. (" << x << "," << y << "), width = " << w << ", height = " << h << endl;
    }

    virtual void draw() {
        cout << "RectangleAdapter: draw." << endl;
        oldDraw();
    }
};

int main() {
    Rectangle* r = new RectangleAdapter(120, 200, 60, 40);
    r->draw();
    return 0;
}
#endif

#ifdef POLYMORPHISM
class ExecuteInterface {
    public:
        virtual ~ExecuteInterface() {}
        virtual void execute() = 0;
};

template <typename TYPE>
class ExecuteAdapter: public ExecuteInterface {
    public:
        ExecuteAdapter(TYPE* o, void(TYPE::*m)()) {
            objec = o;
            method = m;
        }

        ~ExecuteAdapter() {
            delete object;
        }

        void execute() {
            (object->*method)();
        }

    private:
        TYPE* object;
        void(TYPE::*method)();
} ;

class Fea {
    public:
        ~Fea() {
            cout << "Fea::dtor" << endl;
        }

        void doThis() {
            cout << "Fea::doThis()" << endl;
        }
};

class Feye {
    public:
        ~Feye() {
            cout << "Feye:dtor" << endl;
        }

        void doThat() {
            cout << "Feye::doThat()" << endl;
        }
};

class Pheau {
    public
        ~Pheau() {
            cout << "Pheau::dtor" << endl;
        }

    void doTheOther() {
        cout << "Pheau::doTheOther()" << endl;
    }
};

ExecuteInterface** initialize() {
    ExecuteInterface** array = new ExecuteInterface*[3];

    array[0] = new ExecuteAdapter<Fea>(new Fea(), &Fea::doThis);
    array[1] = new ExecuteAdapter<Feye>(new Feye(), &Feye::doThat);
    array[2] = new ExecuteAdapter<Pheau>(new Pheau(), &Pheay::doTheOhter);

    return array;
}

int main() {
    ExecuteInterface** objects = initialize();

    for (int i = 0; i < 3; ++i) {
        objects[i]->execute();
    }

    for (int i = 0; i < 3; ++i) {
        delete objects[i];
    }

    delete objects;
    return 0;
}
#endif
