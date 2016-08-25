#include <iostream>
#include <vector>

using namespace std;

#ifdef NORMAL
enum imageType {
    LSAT, SPOT
};

class Image {
    public:
        virtual void draw() = 0;
        // Can't delete pointer in _prototypes vector, because
        // if it is a pointer to subclass, it would cause circular
        // destruction.
        virtual ~Image() { }

        static Image* findAndClone(imageType);

    protected:
        virtual imageType returnType() = 0;
        virtual Image* clone() = 0;

        static void addPrototype(Image* image) {
            _prototypes.push_back(image);
        }

    private:
        // client side use shared_ptr to manage instance of Image and free it
        // If we use vector<shared_ptr<Image>>, it would require a default instance
        // for shared_ptr<Image>(). And Image is a pure virtual class, we can NOT
        // instantiate it.
        static vector<Image*> _prototypes;
};

vector<Image*>Image::_prototypes;

Image* Image::findAndClone(imageType type) {
    auto itr = find_if(_prototypes.begin(), _prototypes.end(), [&type](Image* i) { 
        if (i->returnType() == type) {
            return true;
        }
        else {
            return false;
        }
    });

    return itr != _prototypes.end() ? (*itr)->clone() : nullptr;
}

class LandSatImage: public Image {
    public:
        imageType returnType() {
            return LSAT;
        }

        void draw() {
            cout << "LandSatImage::draw " << _id << endl;
        }

        Image* clone() {
            return new LandSatImage(1);
        }

    protected:
        LandSatImage(int dummy) {
            _id = _count++;
        }

    private:
        static LandSatImage _landSatImage;
        // this ctor will be called by static variable instantiation
        LandSatImage() {
            addPrototype(this);
        }

        int _id;
        static int _count;
};

LandSatImage LandSatImage::_landSatImage;
int LandSatImage::_count = 1;

class SpotImage: public Image {
    public:
        imageType returnType() {
            return SPOT;
        }

        void draw() {
            cout << "SpotImage::draw " << _id << endl;
        }

        Image* clone() {
            return new SpotImage(1);
        }

    protected:
        SpotImage(int dummy) {
            _id = _count++;
        }

    private:
        static SpotImage _spotImage;
        // this ctor will be called by static variable instantiation
        SpotImage() {
            addPrototype(this);
        }

        int _id;
        static int _count;
};

SpotImage SpotImage::_spotImage;
int SpotImage::_count = 1;

const vector<imageType> input = {
    LSAT, LSAT, LSAT, SPOT, LSAT, SPOT, SPOT, LSAT
};

int main() {
    vector<shared_ptr<Image>> images;

    for (auto &i: input) {
        images.push_back(shared_ptr<Image>(Image::findAndClone(i)));
    }

    for (auto &i: images)
    {
        i->draw();
    }
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
            default:
                {
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
        virtual Stooge* clone() = 0;
        virtual void slap_stick() = 0;
        virtual ~Stooge() {}
};

class Factory {
    public:
        static Stooge* make_stooge(int choice);
    private:
        // Because Stooge is a pure virtual class, it can't be instantiated.
        // We can NOT use vector<Stooge> that needs to instantiate Stooge.
        static vector<Stooge *> s_prototypes;
};

int main() {
    vector<shared_ptr<Stooge>> roles;
    int choice = 0;

    while (true) {
        cout << "Larry(1) Moe(2) Curly(3) Go(0): ";
        cin >> choice;

        if (choice <= 0 || choice > 3) {
            break;
        }

        roles.push_back(shared_ptr<Stooge>(Factory::make_stooge(choice)));
    }

    for (auto &a: roles) {
        a->slap_stick();
    }
}

class Larry: public Stooge {
    public:
        Stooge* clone() { return new Larry; }
        void slap_stick() {
            cout << "Larry: poke eyes" << endl;
        }
};

class Moe: public Stooge {
    public:
        Stooge* clone() { return new Moe; }
        void slap_stick() {
            cout << "Moe: slap head" << endl;
        }
};

class Curly: public Stooge {
    public:
        Stooge* clone() { return new Curly; }
        void slap_stick() {
            cout << "Curly: suffer abuse" << endl;
        }
};

vector<Stooge*> Factory::s_prototypes = {
    nullptr, new Larry, new Moe, new Curly
};

Stooge* Factory::make_stooge(int choice) {
    return s_prototypes[choice]->clone();
}
#endif
