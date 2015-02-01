#include <iostream>
#include <vector>

using namespace std;

const int NUM = 11;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int majority = 0, count = 0;

        for (vector<int>::iterator itr = num.begin(); itr != num.end(); ++itr)
        {
            // Be careful when count becomes 0.
            // Previously I use itr == num.begin() for initialization condition.
            // However, that misses the situation when count becomes 0 majority
            // needs to be reinitialized.
            if (count == 0)
            {
                majority = *itr;
                count++;
            }
            else
            {
                if (majority == *itr)
                {
                    count++;
                }
                else
                {
                    count--;
                    
                    if (count == 0)
                    {
                        majority = 0;
                    }
                }
            }
        }
        
        return majority;
    }
};

int main()
{
    Solution sln;
    int numbers[NUM] = {7, 3, 5, 7, 0, 7, 7, 7, 4, 2, 7};
    vector<int> v(numbers, numbers + NUM);
    cout << "The majority Element of vector is: " << sln.majorityElement(v) << endl;
    return 0;
}

