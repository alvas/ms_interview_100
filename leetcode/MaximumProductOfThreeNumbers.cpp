#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int sz = nums.size();

        if (sz < 3) 
            return 0;
        else if (sz == 3)
            return nums[0] * nums[1] * nums[2];

        int maxV = 0;
        std::sort(nums.begin(), nums.end(), std::greater<int>());

        //if (nums[2] > 0)
        //{
            maxV = nums[0] * nums[1] * nums[2];
            // be careful about the case when two negative time a positive is bigger than product of three positive
            maxV = max(maxV, nums[0] * nums[sz - 1] * nums[sz - 2]);
        //}
        //else if (nums[2] <= 0)
            //maxV = nums[0] * nums[sz - 1] * nums[sz - 2];
        
        return maxV;
    }
};

int main()
{
    Solution sln;
    //vector<int> nums = {1, 2, 3};
    //vector<int> nums = {1, 2, 3, 4};
    vector<int> nums = {722,634,-504,-379,163,-613,-842,-578,750,951,-158,30,-238,-392,-487,-797,-157,-374,999,-5,-521,-879,-858,382,626,803,-347,903,-205,57,-342,186,-736,17,83,726,-960,343,-984,937,-758,-122,577,-595,-544,-559,903,-183,192,825,368,-674,57,-959,884,29,-681,-339,582,969,-95,-455,-275,205,-548,79,258,35,233,203,20,-936,878,-868,-458,-882,867,-664,-892,-687,322,844,-745,447,-909,-586,69,-88,88,445,-553,-666,130,-640,-918,-7,-420,-368,250,-786};
    cout << sln.maximumProduct(nums) << endl;
    return 0;
}
