#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        int sz = nums.size();
        v.reserve(sz);

        for (int i = 0; i < sz; ++i)
        {
            if (i == 0)
            {
                v[i] = nums[i];
            }
            else
            {
                v[i] = v[i - 1] + nums[i];
            }
        }
    }

    int sumRange(int i, int j) {
        if (i <= 0)
        {
            return v[j];
        }
        else
        {
            return v[j] - v[i - 1];
        }
    }
private:
    vector<int> v;
};

//class NumArray {
//public:
    //NumArray(vector<int> &nums) {
        //int sz = nums.size();
        //v.assign(sz, vector<int>(sz, 0));

        //for (int i = 0; i < sz; ++i)
        //{
            //for (int j = i; j < sz; ++j)
            //{
                //if (i == j)
                //{
                    //v[i][j] = nums[i];
                //}
                //else
                //{
                    //v[i][j] = v[i][j - 1] + nums[j];
                //}
            //}
        //}
    //}

    //int sumRange(int i, int j) {
        //return v[i][j];
    //}
//private:
    //vector<vector<int>> v;
//};


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
