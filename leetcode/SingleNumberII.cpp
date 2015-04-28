#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

const int LENGTH = 19;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size = nums.size();
        int x = 0, y = 0, z = 0;

        for (int i = 0; i < size; ++i)
        {
            //// when the number appears first time, set x to the num[i];
            x ^= ~y & nums[i];
            //// when the number appaers second time, set x to 0, and y to num[i];
            y ^= ~x & nums[i];
            //// when the number appears the third time, set y to 0;
            //cout << "x: " << x << "\ty: " << y << "\tnums[i]: " << nums[i] << endl;
            //bitset<32> x1(x), y1(y), n1(nums[i]);
            //cout << "x: " << x1 << "\ty: " << y1 << "\tnums[" << i << "]:\t" << n1 << endl;
            //
            //this can be extended to n numbers
            //x ^= (~y & ~z & a);
            //y ^= (~x & ~z & a);
            //z ^= (~x & ~y & a);
 
            //// when the number appears first time, set x to the num[i];
            //// when the number appaers second time, set x to 0, and y to num[i];
            //// when the number appears third time, y is still num[i], x is reset to num[i]
            //// and z is set to ~num[i], then x and y are clear to 0 later.
            //y |= x & nums[i];
            //x ^= nums[i];
            //z = ~(x & y);
            //cout << "x: " << x << "\ty: " << y << "\tz: " << z << endl;
            //bitset<32> x1(x), y1(y), z1(z);
            //cout << "x: " << x1 << "\ty: " << y1 << "\tz:" << z1 << endl;
            //x &= z;
            //y &= z;
        }

        return x;
    }
};

int main()
{
    Solution sln;
    int a[LENGTH] = {7, 7, 7, 2, 2, 2, 9, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6};
    vector<int> nums(a, a + LENGTH);
    cout << sln.singleNumber(nums) << endl;
    return 0;
}
