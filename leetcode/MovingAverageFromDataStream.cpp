#include <iostream>
#include <queue>

using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        windowSize = size;
        amount = 0.0;
    }
    
    double next(int val) {
        q.push(val);

        if (q.size() <= windowSize) {
            amount += val;
            return amount / q.size();
        }
        else {
            int f = q.front();
            q.pop();
            amount = amount - f + val;
            return amount / windowSize;
        }
    }

private:
    queue<int> q;
    double amount;
    int windowSize;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
int main() {
    MovingAverage ma(3);
    cout << ma.next(1) << endl;
    cout << ma.next(10) << endl;
    cout << ma.next(3) << endl;
    cout << ma.next(5) << endl;
    return 0;
}
