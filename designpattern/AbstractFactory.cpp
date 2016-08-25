#include <iostream>
#include <memory>
#include <vector>

using namespace std;

#ifdef NORMAL
class Shape {
    public:
        Shape() { id_ = total_++; }
        virtual void draw() = 0;
        virtual ~Shape() {}
    protected:
        int id_;
        static int total_;
};

int Shape::total_ = 0;

class Circle : public Shape {
    public:
        void draw() {
            cout << "circle " << id_ << ": draw" << endl;
        }
};

class Square : public Shape {
    public:
        void draw() {
            cout << "Square " << id_ << ": draw" << endl;
        }
};

class Ellipse : public Shape {
    public:
        void draw() {
            cout << "ellipase " << id_ << ": draw" << endl;
        }
};

class Rectangle : public Shape {
    public:
        void draw() {
            cout << "rectangle " << id_ << ": draw" << endl;
        }
};

class Factory {
    public:
        virtual Shape* createCurvedInstance() = 0;
        virtual Shape* createStraightInstance() = 0;
};

class SimpleShapeFactory : public Factory {
    public:
        Shape* createCurvedInstance() {
            return new Circle;
        }

        Shape* createStraightInstance() {
            return new Square;
        }
};

class RobustShapeFactor : public Factory {
    public:
        Shape* createCurvedInstance() {
            return new Ellipse;
        }

        Shape* createStraightInstance() {
            return new Rectangle;
        }
};

int main() {
    Factory* factory = nullptr;
#ifdef SIMPLE
    factory = new SimpleShapeFactory;
#elif ROBUST
    factory = new RobustShapeFactory;
#endif

    // It is not vector<shared_ptr<Shape*>> shapes;
    vector<shared_ptr<Shape>> shapes;
    shapes.push_back(shared_ptr<Shape>(factory->createCurvedInstance()));
    shapes.push_back(shared_ptr<Shape>(factory->createStraightInstance()));
    shapes.push_back(shared_ptr<Shape>(factory->createCurvedInstance()));

    for (auto &s: shapes) {
        s->draw();
    }

    return 0;
}
#endif

class Widget {
    public:
        virtual void draw() = 0;
};

class LinuxButton: public Widget {
    public:
        void draw() {
            cout << "LinuxButton" << endl;
        }
};

class LinuxMenu: public Widget {
    public:
        void draw() {
            cout << "LinuxMenu" << endl;
        }

};

class WindowsButton: public Widget {
    public:
        void draw() {
            cout << "WindowsButton" << endl;
        }
};

class WindowsMenu: public Widget {
    public:
        void draw() {
            cout << "WindowMenu" << endl;
        }
};

#ifdef BEFORE
class Client {
    public:
        void draw() {
#ifdef LINUX
            Widget* w = new LinuxButton;
#else
            Widget* w = new LinuxButton;
#endif

            w->draw();
            display_window_one();
            display_window_two();
        }

        void display_window_one() {
#ifdef LINUX
            Widget *w[] = {
                new LinuxButton,
                new LinuxMenu
            };
#else
            Widget *w[] = {
                new WindowsButton,
                new WindowsMenu
            };
#endif

            w[0]->draw();
            w[1]->draw();
        }

        void display_window_two() {
#ifdef LINUX
            Widget *w[] = {
                new LinuxMenu,
                new LinuxButton
            };
#else
            Widget *w[] = {
                new WindowsMenu,
                new WindowsButton
            };
#endif

            w[0]->draw();
            w[1]->draw();
        }
};

int main() {
    Client c;
    c.draw();
}
#endif

#ifdef AFTER
class Factory {
    public:
        virtual Widget* create_button() = 0;
        virtual Widget* create_menu() = 0;
};

class LinuxFactory: public Factory {
    public:
        Widget* create_button() {
            return new LinuxButton;
        }

        Widget* create_menu() {
            return new LinuxMenu;
        }
};

class WindowsFactory: public Factory {
    public:
        Widget* create_button() {
            return new WindowsButton;
        }

        Widget* create_menu() {
            return new WindowsMenu;
        }
};

class Client {
    private:
        Factory* factory;

    public:
        Client(Factory* f): factory(f) { }

        void draw() {
            Widget* w = factory->create_button();
            w->draw();
            display_window_one();
            display_window_two();
        }

        void display_window_one() {
            Widget *w[] = {
                factory->create_button(),
                factory->create_menu()
            };

            w[0]->draw();
            w[1]->draw();
        }

        void display_window_two() {
            Widget *w[] = {
                factory->create_menu(),
                factory->create_button()
            };

            w[0]->draw();
            w[1]->draw();
        }
};

int main() {
    Factory* factory = nullptr;

#ifdef LINUX
    factory = new LinuxFactory;
#else
    factory = new WindowsFactory;
#endif

    Client c(factory);
    c.draw();
}
#endif
