#include <iostream>
#include <set>

using namespace std;

class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
       s.insert(number); 
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto i: s) {
            int j = value - i;
            if ((j != i && s.count(j) != 0) || (j == i && s.count(i) > 1)) {
                return true;
            }
        }

        return false;
    }

private:
    multiset<int> s;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */

int main()
{
    TwoSum ts;
    ts.add(1);
    ts.add(3);
    ts.add(5);
    cout << ts.find(4) << endl;
    cout << ts.find(7) << endl;
    cout << ts.find(0) << endl;
    return 0;
}
