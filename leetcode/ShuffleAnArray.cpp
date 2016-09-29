#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        v1.swap(nums); 
        output = v1; 
        std::srand(unsigned(std::time(0)));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        output.clear();
        output = v1;
        return output;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        //std::random_shuffle(output.begin(), output.end());
        int sz = output.size();

        for (int i = 0; i < sz; ++i) {
            int r = rand() % sz;
            swap(output[i], output[r]);
        }

        return output;
    }

    vector<int> v1, output;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

int main() {
    vector<int> nums = {1, 2, 3};
    Solution sln(nums);
    vector<int> param_1 = sln.reset();
    printVector<int>(param_1);
    vector<int> param_2 = sln.shuffle();
    printVector<int>(param_2);
    return 0;
}
