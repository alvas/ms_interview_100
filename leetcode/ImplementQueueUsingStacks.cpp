#include <iostream>
#include <stack>

using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        inputS.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (outputS.empty())
        {
            if (!inputS.empty())
            {
                while (!inputS.empty())
                {
                    outputS.push(inputS.top());
                    inputS.pop();
                }
            }
        }

        if (!outputS.empty())
        {
            outputS.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        if (!outputS.empty())
        {
            return outputS.top();
        }
        else if (!inputS.empty())
        {
            while (!inputS.empty())
            {
                outputS.push(inputS.top());
                inputS.pop();
            }

            return outputS.top();
        }
        else
        {
            return 0;
        }
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return inputS.empty() && outputS.empty();
    }

    stack<int> inputS, outputS;
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    std::cout << "Is queue empty? " << q.empty() << endl;

    while (!q.empty())
    {
        std::cout << "poping " << q.peek() << " from front of the queue." << endl;
        q.pop();
    }

    return 0;
}
