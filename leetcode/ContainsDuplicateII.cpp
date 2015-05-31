#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    }
};

int main()
{
    Solution sln;
    int k = 0;
    int a[] = {};
    //int a[] = {1, 2};
    //int a[] = {1, 1};
    //int a[] = {1, 2, 3};
    int a[LOCAL_LENGTH] = {1, 2, 2, 3};
    vector<int> nums(a, a + SIZE());
    cout << "Please enter k: ";
    cin >> k;
    cout << sln.containsNearbyDupplicate(nums, k) << endl;
    return 0;
}
