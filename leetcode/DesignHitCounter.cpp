#include <iostream>
#include <queue>

using namespace std;

class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        q.push(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        if (q.empty()) {
            return 0;
        }
        else {
            int a = timestamp - 300;

            if (a < 0) {
                a = 0;
            }

            // Be careful when q is empty.
            while (!q.empty() && q.front() <= a) {
                q.pop();
            }

            return q.size();
        }
    }
private:
    queue<int> q;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
int main() {
    HitCounter hc;
    hc.hit(1);
    hc.hit(2);
    hc.hit(3);
    cout << hc.getHits(4) << endl;
    hc.hit(300);
    cout << hc.getHits(300) << endl;
    cout << hc.getHits(301) << endl;
    return 0;
}
