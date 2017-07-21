#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);

        for (int i = 1; i < flowerbed.size() - 1; ++i) {
            if (flowerbed[i - 1] + flowerbed[i] + flowerbed[i + 1] == 0) {
                n--;
                i++;
            }
        }

        return n <= 0;
    }

    bool canPlaceFlowers1(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();

        // various conditions
        for (int i = 0; i < sz; ++i) {
            if (i == 0) {
                if (!flowerbed[i] && i + 1 < sz && !flowerbed[i + 1]) {
                    flowerbed[i] = 1;
                    n--;
                }
                else if (!flowerbed[i] && i + 1 >= sz) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            else if (i == sz - 1) {
                if (!flowerbed[i] && i - 1 >= 0 && !flowerbed[i - 1]) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            else if (!flowerbed[i - 1] && !flowerbed[i] && !flowerbed[i + 1]) {
                flowerbed[i] = 1;
                n--;
            }
        }

        return n <= 0;
    }
};

int main()
{
    Solution sln;
    //vector<int> flowerbed = {1, 0, 0, 0, 1};
    //vector<int> flowerbed = {0, 0, 1, 0, 1};
    //vector<int> flowerbed = {1, 0, 0, 0, 0, 1};
    vector<int> flowerbed = {0};
    int n = 1;
    cout << sln.canPlaceFlowers(flowerbed, n) << endl;
    return 0;
}
