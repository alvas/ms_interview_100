#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        auto itr = m.find(message);

        if (itr == m.end()) {
            m[message] = timestamp;
            return true;
        }
        else {
            int prevTimestamp = itr->second;

            if (timestamp - prevTimestamp >= 10) {
                m[message] = timestamp;
                return true;
            }
            else {
                return false;
            }
        }
    }
private:
    unordered_map<string, int> m;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */
int main() {
    Logger logger;
    cout << logger.shouldPrintMessage(1, "foo");
    cout << logger.shouldPrintMessage(2,"bar");
    cout << logger.shouldPrintMessage(3,"foo");
    cout << logger.shouldPrintMessage(8,"bar");
    cout << logger.shouldPrintMessage(10,"foo");
    cout << logger.shouldPrintMessage(11,"foo");
    return 0;
}
