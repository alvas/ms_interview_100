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
        virtual ~Image() {}
        static Image *findAndClone(imageType);
    protected:
        virtual imageType returnType() = 0;
        virtual Image* clone() = 0;

        static void addPrototype(Image* image)
        {
            _prototypes[_nextSlot++] = image;
        }

    private:
        static Image* _prototypes[10];
        static int _nextSlot;
};

Image* Image::_prototypes[];
int Image::_nextSlot;

Image* Image::findAndClone(imageType type) {
    for (int i = 0; i < _nextSlot; ++i) {
        if (_prototypes[i]->returnType() == type) {
            return _prototypes[i]->clone();
        }
    }

    return nullptr;
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
        SpotImage() {
            addPrototype(this);
        }

        static SpotImage _spotImage;
        int _id;
        static int _count;
};

SpotImage SpotImage::_spotImage;
int SpotImage::_count = 1;

const int NUM_IMAGES = 8;
imageType input[NUM_IMAGES] = {
    LSAT, LSAT, LSAT, SPOT, LSAT, SPOT, SPOT, LSAT
};

int main()
{
    Image *images[NUM_IMAGES];

    for (int i = 0; i < NUM_IMAGES; ++i) {
        images[i] = Image::findAndClone(input[i]);
    }

    for (int i = 0; i < NUM_IMAGES; ++i) {
        images[i]->draw();
    }

    for (int i = 0; i < NUM_IMAGES; ++i) {
        delete images[i];
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

int main()
{
    vector<Stooge*> roles;
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
            default:
                {
                    break;
                }
        }
    }

    for (auto &a: roles) {
        a->slap_stick();
    }

    for (auto &a: roles) {
        delete a;
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
        static Stooge* s_prototypes[4];
};

int main() {
    vector<Stooge*> roles;
    int choice = 0;

    while (true) {
        cout << "Larry(1) Moe(2) Curly(3) Go(0): ";
        cin >> choice;

        if (choice <= 0 || choice > 3) {
            break;
        }

        roles.push_back(Factory::make_stooge(choice));
    }

    for (auto &a: roles) {
        a->slap_stick();
    }

    for (auto &a: roles) {
        delete a;
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

Stooge* Factory::s_prototypes[] = {
    0, new Larry, new Moe, new Curly
};

Stooge* Factory::make_stooge(int choice) {
    return s_prototypes[choice]->clone();
}
#endif
