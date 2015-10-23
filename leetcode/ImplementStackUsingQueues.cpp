#include <cassert>
#include <iostream>
#include <queue>

using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if (!q.empty())
        {
            int top = q.front();
            q.pop();
            cached.push(top);
        }

        q.push(x);
        //assert(q.size() == 1);
    }

    // Removes the element on top of the stack.
    void pop(void) {
        q.pop();

        if (!cached.empty())
        {
            int sz = cached.size();

            while (!cached.empty())
            {
                int front = cached.front();
                cached.pop();
                q.push(front);
            }

            for (int i = 0; i < sz - 1; ++i)
            {
                int front = q.front();
                q.pop();
                cached.push(front);
            }
        }
        // Can't write this in leetcode, otherwise, it would get runtime error because of this assertion. i.e. push, pop, empty
        //else
        //{
            //assert(false);
        //}
    }

    // Get the top element.
    int top(void) {
        if (!q.empty())
        {
            return q.front();
        }
        //else if (!cached.empty())
        //{
            //assert(false);
        //}
        else
        {
            return 0;
        }
    }

    // Return whether the stack is empty.
    bool empty(void) {
        // actually only need to check q.empty() because if the stack is not empty, there must be exactly 1 element on q.
        return q.empty() && cached.empty();
    }

    queue<int> q;
    queue<int> cached;
};

int main()
{
    Stack s;
    
    for (int i = 0; i < 15; ++i)
    {
        s.push(i);
    }

    std::cout << "Is stack empty: " << s.empty() << endl;

    while (!s.empty())
    {
        std::cout << "Top of the stack: " << s.top() << endl;
        s.pop();
    }

    return 0;
}
