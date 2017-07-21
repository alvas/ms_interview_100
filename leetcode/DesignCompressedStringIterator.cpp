#include <iostream>
#include <string>

using namespace std;

class StringIterator {
public:
    StringIterator(string compressedString) {
        str = compressedString;
        bItr = str.begin();
        eItr = str.end();
        count = 0;

        if (bItr != eItr) {
            c = *bItr;
            bItr++;

            while (bItr != eItr && isdigit(*bItr)) {
                count = count * 10 + *bItr - '0';
                bItr++;
            }
        }
    }
    
    char next() {
        if (bItr == eItr && count == 0) {
            return ' ';
        }
        else {
            char res = c;
            count--;

            if (count == 0 && bItr != eItr) {
                c = *bItr;
                bItr++;

                while (bItr != eItr && isdigit(*bItr)) {
                    count = count * 10 + *bItr - '0';
                    bItr++;
                }
            }

            return res;
        }
    }
    
    bool hasNext() {
        return !(bItr == eItr && count == 0);
    }

private:
    // Need to preserve the string, otherwise, iterator would become invalid.
    string str;
    string::iterator bItr;
    string::iterator eItr;
    char c;
    int count;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */

int main()
{
    //StringIterator itr("L1e2t1C1o1d1e1");
    StringIterator itr("G4X10v8G17x15");
    std::cout << itr.next() << endl; // return 'L'
    std::cout << itr.next() << endl; // return 'e'
    std::cout << itr.next() << endl; // return 'e'
    std::cout << itr.next() << endl; // return 't'
    std::cout << itr.next() << endl; // return 'C'
    std::cout << itr.next() << endl; // return 'o'
    std::cout << itr.next() << endl; // return 'd'
    std::cout << itr.hasNext() << endl; // return true
    std::cout << itr.next() << endl; // return 'e'
    std::cout << itr.hasNext() << endl; // return false
    std::cout << itr.next() << endl; // return ' '
    return 0;
}
