#include <iostream>

using namespace std;

class MiniStackData
{
    public:
        MiniStackData(int, int, MiniStackData *);
        int getData();
        int getMini();
        MiniStackData *getNext();
    private:
        int data;
        int mini;
        MiniStackData *next;
};

class MiniStack
{
    public:
        MiniStack();
        // !!If we don't implement the copy constructor, don't implement the deconstructor;
        // otherwise, if a stack is passsed as an argument to a function, the stack would be
        // copied and the deconstructor would be called to destroy the copy when the function 
        // exits. Then it would free the stack data and cause corruption.
//        ~MiniStack();
        void push(int);
        int pop();
        int mini();
        int getSize();
        MiniStackData *getTop();

    private:
        MiniStackData *top;
        int size;
};

MiniStackData::MiniStackData(int num, int miniNum, MiniStackData *top)
{
    data = num;
    mini = miniNum;
    next = top;
    cout << "num = " << num << "; mini = " << mini << "; next = " << next << endl;
}

int MiniStackData::getData()
{
    return data;
}

int MiniStackData::getMini()
{
    return mini;
}

MiniStackData *MiniStackData::getNext()
{
    return next;
}


MiniStack::MiniStack()
{
    top = NULL;
    size = 0;
}

//MiniStack::~MiniStack()
//{
//    while (top != NULL)
//    {
//        pop();
//    }
//}

void MiniStack::push(int num)
{
    int miniNum = 0;

    if (top == NULL)
    {
        miniNum = num;
    }
    else
    {
        miniNum = num > mini() ? mini() : num;
    }

    MiniStackData *stackData = new MiniStackData(num, miniNum, top);

    size++;

    top = stackData;
    cout << "pusing num = " << num << "; mini = " << miniNum << "; top = " << top << endl;
}

int MiniStack::pop()
{
    if (top == NULL)
    {
        cerr << "Stack is empty!" << endl;
        exit(0);
    }

    MiniStackData *topData = top;
    int elem = top->getData();
    top = top->getNext();
    delete topData;
    size--;
    return elem;
}

int MiniStack::mini()
{
    if (top == NULL)
    {
        cerr << "Stack is empty!" << endl;
        exit(0);
    }

    return top->getMini();
}

MiniStackData *MiniStack::getTop()
{
    return top;
}

static void printStack(MiniStackData *top)
{
    MiniStackData *ptr = top;
    cout << "ptr = " << ptr << endl;
    cout << "the current stack is:" << endl;

    while (ptr != NULL)
    {
        cout << ptr->getData() << "\t";
        ptr = ptr->getNext();
        cout << "next = " << ptr << "\t";
    } 

    cout << endl;
}

// !!If we implement the destructor, but not copy constructor,
// don't pass stack to the function, otherwise, it would be copied.
// And the copied stack would be freed at the end which would destroy
// all data in the stack!!
// If we pass the reference, it should be ok.
static void printStack(MiniStack &stack)
{
    MiniStackData *ptr = stack.getTop();
    cout << "the current stack is:" << endl;

    while (ptr != NULL)
    {
        cout << ptr->getData() << "\t";
        ptr = ptr->getNext();
    } 

    cout << endl;
}

static void freeStack(MiniStack stack)
{
    while (stack.getTop() != NULL)
    {
        int data = stack.pop();
//        cout << "destrying: " << data << endl;
    }
}

int main()
{
//    int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int a[10] = {9, 8, 17, 36, 25, 784, 3, 992, 12, 0};
    MiniStack stack;

    for (int i = 0; i < 10; ++i)
    {
        stack.push(a[i]);
        cout << "The mini of the stack is: " << stack.mini() << endl << endl;
    }

//        printStack(stack.getTop());
    printStack(stack);
    freeStack(stack);

    return 0;
}
