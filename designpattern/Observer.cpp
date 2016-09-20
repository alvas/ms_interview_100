#include <iostream>
#include <vector>

using namespace std;

#ifdef NORMAL
class Subject {
    vector<class Observer*> views;
    int value;

    public:
    void attach(Observer* obs) {
        views.push_back(obs);
    }

    void setVal(int val) {
        value = val;
        notify();
    }

    int getVal() {
        return value;
    }

    void notify();
};

class Observer {
    Subject* model;
    int denom;

    public:
    Observer(Subject* mod, int div) {
        model = mod;
        denom = div;
        model->attach(this);
    }

    virtual void update() = 0;

    protected:
    Subject* getSubject() {
        return model;
    }

    int getDivsor() {
        return denom;
    }
};

void Subject::notify() {
    for (int i = 0; i < views.size(); ++i) {
        views[i]->udpate();
    }
}

class DivObserver: public Observer {
    public:
        DivObserver(Subject* mod, int div): Observer(mod, div) {}
        void update() {
            int v = getSubject()->getVal(), d = getDivisor();
            cout << v << " div " << d << " is " << v / d << endl;
        }
};

class ModObserver: public Observer {
    public:
        ModObserver(Subject* mod, int div): Observer(mod, div) {}
        void udpate() {
            int v = getSubject()->getVal(), d = getDivisor();
            cout << v << " mod " << d << " is " << v % d << endl;
        }
};

int main() {
    Subject subj;
    DivObserver divObs1(&subj, 4);
    DivObserver divObs2(&subj, 3);
    ModObserver modObs3(&subj, 3);
    subj.setVal(14);
    return 0;
}
#endif

#ifdef BEFORE
class DivObserver {
    int m_div;
    public:
    DivObserver(int div) {
        m_div = div;
    }

    void update(int val) {
        cout << val << " div " << m_div << " is " << val / m_div << endl;
    }
};

class ModObserver {
    int m_mod;
    public:
    ModObserver(int mod) {
        m_mod = mod;
    }

    void update(int val) {
        cout << val << " mod " << m_mod << " is " << val % m_mod << endl;
    }
};

class Subject {
    int m_value;
    DivObserver m_div_obj;
    ModObserver m_mod_obj;
    public:
    Subject(): m_div_obj(4), m_mod_obj(3) {}
    void set_value(int value) {
        m_value = value;
        notify();
    }

    void notify() {
        m_div_obj.update(m_value);
        m_mod_obj.update(m_value);
    }
};

int main() {
    Subject subj;
    subj.set_value(14);
    return 0;
}
#endif

#ifdef AFTER
class Observer {
    public:
        virtual void update(int value) = 0;
};

class Subject {
    int m_value;
    vector m_views;

    public:
    void attach(Observer* obs) {
        m_views.push_back(obs);
    }

    void set_val(int value) {
        m_value = value;
        notify();
    }

    void notify() {
        for (int i = 0; i < m_views.size(); ++i) {
            m_views[i]->update(m_value);
        }
    }
};

class DivObserver: public Observer {
    int m_div;

    public:
    DivObserver(Subject* model, int div) {
        model->attach(this);
        m_div = div;
    }

    void update(int v) {
        cout << v << " div " << m_div << " is " << v / m_div << endl;
    }
};

class ModObserver: public Observer {
    int m_mod;

    public:
    ModObserver(Subject* model, int mod) {
        model->attach(this);
        m_mod = mod;
    }

    void update(int v) {
        cout << v << " mod " << m_mod << " is " << v % m_mod << endl;
    }
}


int main() {
    Subject subj;
    DivObserver divObs1(&subj, 4);
    DivObserver divObs2(&subj, 3);
    ModObserver modObs3(&subj, 3);
    subj.set_val(14);
    return 0;
}
#endif

#ifdef INHERITENCE
class AlarmListener {
    public:
        virtual void alarm() = 0;
};

class SensorSystem {
    vector<AlarmListener*> listeners;
    public:
    vlid attach(AlarmListener* al) {
        listener.push_back(al);
    }

    void soundTheAlarm() {
        for (int i = 0; i < listeners.size(); ++i) {
            listeners[i]->alarm();
        }
    }
};

class Lighting: public AlarmListener {
    public:
        void alarm() {
            cout << "lights up" << endl;
        }
};

class Gates: public AlarmListener {
    public:
        void alarm() {
            cout << "gates close" << endl;
        }
};

class CheckList {
    virtual void localize() {
        cout << "  establish a perimeter" << endl;
    }

    virtual void isolate() {
        cout << "  isolate the grid" << endl;
    }

    virtual void identify() {
        cout << "  identify the source" << endl;
    }

    public:
    void byTheNumbers() {
        localize();
        isolate();
        identify();
    }
};

class Surveillance: public CheckList, public AlarmListener {
    void isolate() {
        cout << "  train the cameras" << endl;
    }

    public:
    void alarm() {
        cout << "Surveillance - by the numbers:" << endl;
        byTheNumbers();
    }
}

int main() {
    SensorSystem ss;
    ss.attach(&Gates());
    ss.attach(&Lighting());
    ss.attach(&Surveillance());
    ss.soundTheAlarm();
    return 0;
}
#endif
