#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    void push(int x) {
        data.push(x);

        // WATCH OUT for duplicate data the same of top of min!!
        if (min.empty() || x <= min.top())
        {
            min.push(x);
        }
    }

    // what should be the top if stack is empty
    void pop() {
        if (data.empty())
        {
            return;
        }

        int top = data.top();
        data.pop();

        if (min.top() == top)
        {
            min.pop();
        }
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min.top();
    }

private:
    stack<int> data;
    stack<int> min;
};

int main()
{
    MinStack s;
    s.push(3);
    s.push(8);
    s.push(5);
    s.push(4);
    s.push(1);
    s.push(6);
    std::cout << "top() " << s.top() << endl;
    std::cout << "getMin() " << s.getMin() << endl;
    return 0;
}
