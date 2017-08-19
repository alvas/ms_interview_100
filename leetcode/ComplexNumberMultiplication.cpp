#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ra, ia, rb, ib;
        char buff;
        stringstream aa(a), bb(b), res;
        aa >> ra >> buff >> ia >> buff;
        bb >> rb >> buff >> ib >> buff;
        res << ra * rb - ia * ib << "+" << ra * ib + rb * ia << "i";
        return res.str();
    }

    string complexNumberMultiply1(string a, string b) {
        auto itr1 = a.find("+"), itr2 = b.find("+");
        auto a1 = a.substr(0, itr1), b1 = b.substr(0, itr2);
        auto itr3 = a.find("i"), itr4 = b.find("i");
        auto a2 = a.substr(itr1 + 1, itr3 - itr1 - 1), b2 = b.substr(itr2 + 1, itr4 - itr2 - 1);
        auto ar = stoi(a1), br = stoi(b1), ai = stoi(a2), bi = stoi(b2);
        auto cr = ar * br - ai * bi, ci = ar * bi + ai * br;
        return to_string(cr) + "+" + to_string(ci) + "i";
    }
};

int main()
{
    Solution sln;
    //string a("1+2i"), b("3+4i");
    //string a("1+1i"), b("1+1i");
    string a("1+-1i"), b("1+-1i");
    cout << sln.complexNumberMultiply(a, b) << endl;
    return 0;
}
