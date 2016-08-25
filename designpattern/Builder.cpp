#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class DistrWorkPackage {
    public:
        DistrWorkPackage(const string &type) {
            ostringstream oss;
            oss << "Distributed Work Package for: " << type;
            _desc = oss.str();
        }

        void setFile(const string &f, const string &v) {
            ostringstream oss;
            oss << "\n File(" << f << "): " << v;
            _desc += oss.str();
        }

        void setQueue(const string &q, const string &v) {
            ostringstream oss;
            oss << "\n Queue(" << q << "): " << v;
            _desc += oss.str();
        }

        void setPathway(const string &p, const string &v) {
            ostringstream oss;
            oss << "\n Pathway(" << p << "): " << v;
            _desc += oss.str();
        }

        const string& getState() {
            return _desc;
        }

    private:
        string _desc;
};

class Builder {
    public:
        virtual void configureFile(const string&) = 0;
        virtual void configureQueue(const string&) = 0;
        virtual void configurePathway(const string&)= 0;

        DistrWorkPackage* getResult() {
            return _result;
        }

    protected:
        DistrWorkPackage* _result;
};

class UnixBuilder: public Builder {
    public:
        UnixBuilder() {
            _result = new DistrWorkPackage("Unix");
        }

        ~UnixBuilder() { delete _result; }

        void configureFile(const string &name) {
            _result->setFile("flatFile", name);
        }

        void configureQueue(const string &queue) {
            _result->setQueue("FIFO", queue);
        }

        void configurePathway(const string &type) {
            _result->setPathway("thread", type);
        }
};

class VmsBuilder: public Builder {
    public:
        VmsBuilder() {
            _result = new DistrWorkPackage("Vms");
        }

        ~VmsBuilder() { delete _result; }

        void configureFile(const string &name) {
            _result->setFile("ISAM", name);
        }

        void configureQueue(const string &queue) {
            _result->setQueue("priority", queue);
        }

        void configurePathway(const string &type) {
            _result->setPathway("LWP", type);
        }
};

enum PersistenceType {
    File, Queue, Pathway
};

struct PersistenceAttribute {
    PersistenceType type;
    string value;
};

class Reader {
    public:
        void setBuilder(Builder *b) {
            _builder = b;
        }

        void construct(const vector<PersistenceAttribute>&);

    private:
        Builder* _builder;
};

void Reader::construct(const vector<PersistenceAttribute> &list) {
    for (int i = 0; i < list.size(); ++i) {
        if (list[i].type == File) {
            _builder->configureFile(list[i].value);
        }
        else if (list[i].type == Queue) {
            _builder->configureQueue(list[i].value);
        }
        else if (list[i].type == Pathway) {
            _builder->configurePathway(list[i].value);
        }
    }
}

const vector<PersistenceAttribute> input = {
    {File, "state.dat"},
    {File, "config.sys"},
    {Queue, "computer"},
    {Queue, "log"},
    {Pathway, "authentication"},
    {Pathway, "error processing"}
};

int main()
{
    UnixBuilder unixBuilder;
    VmsBuilder vmsBuilder;
    Reader reader;

    reader.setBuilder(&unixBuilder);
    reader.construct(input);
    cout << unixBuilder.getResult()->getState() << endl;

    reader.setBuilder(&vmsBuilder);
    reader.construct(input);
    cout << vmsBuilder.getResult()->getState() << endl;
    return 0;
}
