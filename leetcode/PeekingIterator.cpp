#include <iostream>
#include <vector>

using namespace std;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const std::vector<int>& nums) {};
    Iterator(const Iterator& iter) {};
    virtual ~Iterator() {};
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    PeekingIterator(const std::vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        //index = 0;
        //size = nums.size();
        //this->nums = &nums;
        itr = new Iterator(nums);

        if (itr->hasNext())
        {
            nextValue = itr->next();
        }
        else
        {
            end = true;
        }
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (end == false)
        {
            return nextValue;
        }
        else
        {
            return 0;
        }
        //return (*nums)[index];
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int current = nextValue;

        if (itr->hasNext())
        {
            nextValue = itr->next();
        }
        else
        {
            end = true;
        }

        return current;
        //return (*nums)[index++];
        //return Iterator::next();
    }

    bool hasNext() const {
        if (end == true)
        {
            return false;
        }
        else
        {
            return true;
        }
        //return index < size;
        //return Iterator::hasNext();
    }

    //int index;
    //int size;
    //const vector<int> *nums;
    Iterator *itr;
    int nextValue = 0;
    bool end = false;
};

int main()
{
    vector<int> nums = {1, 2, 3};
    PeekingIterator itr(nums);
    std::cout << itr.peek() << std::endl;
    std::cout << itr.next() << std::endl;
    std::cout << itr.next() << std::endl;
    std::cout << itr.peek() << std::endl;
    std::cout << itr.hasNext() << std::endl;
    return 0;
}
