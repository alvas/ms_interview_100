#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        v = nums;
    }

    int sumRange(int i, int j) {
        if (i < 0)
        {
            return 0;
        }
        else if (i >= v.size())
        {
            return 0;
        }

        int sum = 0;

        for (int s = i; s <= j; ++s)
        {
            sum += v[s];
        }

        return sum;
    }
private:
    vector<int> v;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

int main()
{
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray a(nums);
    std::cout << a.sumRange(0, 2) << std::endl;
    std::cout << a.sumRange(2, 5) << std::endl;
    std::cout << a.sumRange(0, 5) << std::endl;
    std::cout << a.sumRange(0, 1) << std::endl;
    std::cout << a.sumRange(1, 2) << std::endl;
    return 0;
}
