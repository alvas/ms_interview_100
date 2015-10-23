#include <cassert>
#include <iostream>
#include <numeric>
#include <stack>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size());
        candy[0] = 1;
        int i = 1;

        for ( ; i < ratings.size(); ++i)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candy[i] = candy[i - 1] + 1;
            }
            
            if (ratings[i] == ratings[i - 1])
            {
                candy[i] = 1;
            }

            if (ratings[i] < ratings[i - 1])
            {
                candy[i] = candy[i - 1] - 1;
            }

            if (i < ratings.size() - 1 && ratings[i] < ratings[i - 1] && ratings[i] <= ratings[i + 1])
            {
                ReAdjustCandy(ratings, candy, i);
            }
        }

        if (ratings[i - 1] < ratings[i - 1])
        {
            ReAdjustCandy(ratings, candy, ratings.size() - 1);
        }

        int total = 0;

        printVector<int>(candy);

        std::for_each(candy.begin(), candy.end(), [&](int n) {
            total += n;
        });

        return total;
    }

    void ReAdjustCandy(vector<int> &ratings, vector<int> &candy, int startIndex)
    {
        int k = startIndex;
        int diff = 1 - candy[k];

        while (k > 0 && ratings[k - 1] > ratings[k])
        {
            candy[k] = candy[k] + diff;
            k--;
        }

        if (diff > 0)
        {
            candy[k] += diff;
        }
    }

    int candy_buggy(vector<int>& ratings) {
        int sz = ratings.size(), v = 0;
        vector<int> count(sz, 0);
        stack<int> s;

        for (int i = 0; i < sz; ++i)
        {
            if (i == 0)
            {
                v++;
                count[i] = v;
            }
            else
            {
                if (ratings[i - 1] < ratings[i])
                {
                    // simply increasing
                    if (s.empty())
                    {
                        v++;
                        count[i] = v;
                    }
                    else
                    {
                        int a = 1, b = -1, c = -1;

                        // traceback to the peak
                        while (!s.empty())
                        {
                            b = s.top();
                            s.pop();

                            // need to compare the  current top num and the previous poped one.
                            if (c != -1 && ratings[b] == ratings[c])
                            {
                                // IMPORTANT!! Shame on me. I can't figure this out.
                                // For configuration [1, 4, 2, 2, 3], we can have [1, 2, 1, 2, 1].
                                // Which is better than [1, 3, 2, 2, 1] 
                                // When there are equal rating, we can greedy decrease the number.
                                // NOT only decrease by 1!!
                                // Shame on me. If multiple ratings are the same, their value can't 
                                // be set to arbitrary. [4, 4, 4, 4], in this case, [4, 1, 1, 1] or
                                // [4, 2, 1, 2].
                                while (a > 1)
                                {
                                    a--;
                                }

                                count[b] = a++;
                            }
                            // For the first number on backtrace.
                            else if (count[b] <= a)
                            {
                                count[b] = a++;
                            }

                            // We need to save the b value for the peak which is after the bottom of the stack
                            c = b;
                        }

                        // Adjust the peak value after the bottom of the stack, if necessary.
                        if (b > 0 && count[--b] < a)
                        {
                            if (ratings[b] > ratings[b + 1])
                            {
                                count[b] = a;
                            }
                        }

                        v = count[i - 1] + 1;
                        count[i] = v;
                    }
                }
                else
                {
                    s.push(i);
                }
            }
        }

        int a = 1, b = -1, c = -1;

        // IMPORTANT!! Shame on me. I can't figure this out.
        // For configuration [1, 4, 2, 2, 3], we can have [1, 2, 1, 2, 1].
        // Which is better than [1, 3, 2, 2, 1] 
        // When there are equal rating, we can greedy decrease the number.
        // NOT only decrease by 1!!
        while (!s.empty())
        {
            b = s.top();
            s.pop();

            // need to compare the  current top num and the previous poped one.
            if (c != -1 && ratings[b] == ratings[c])
            {
                // IMPORTANT!! Shame on me. I can't figure this out.
                // For configuration [1, 4, 2, 2, 3], we can have [1, 2, 1, 2, 1].
                // Which is better than [1, 3, 2, 2, 1] 
                // When there are equal rating, we can greedy decrease the number.
                // NOT only decrease by 1!!
                while (a > 1)
                {
                    a--;
                }

                count[b] = a++;
            }
            // For the first number on backtrace.
            else if (count[b] <= a)
            {
                count[b] = a++;
            }

            // We need to save the b value for the peak which is after the bottom of the stack
            c = b;
        }

        // Adjust the peak value after the bottom of the stack, if necessary.
        if (b > 0 && count[--b] < a)
        {
            if (ratings[b] > ratings[b + 1])
            {
                count[b] = a;
            }
        }

        return accumulate(count.begin(), count.end(), 0);
    }

/*
 *  This approach can't work, because it only adjust the value after at the end. The adjustement can't be applied to previous peak.
 *
    int candy(vector<int>& ratings) {
        int sz = ratings.size();
        int minV = 0, V = 0, count = 0, prevMaxV= 0;
        bool duplicate = false;

        for (int i = 0; i < sz; ++i)
        {
            if (i == 0)
            {
                V++;
                minV = 1;
            }
            else
            {
                if (ratings[i - 1] < ratings[i])
                {
                    V++;
                    duplicate = false;

                    if (V > 0)
                    {
                        prevMaxV = V;
                    }
                }
                else if (ratings[i - 1] > ratings[i])
                {
                    if (V == 1)
                    {
                        if (duplicate)
                        {
                            count++;
                        }
                        else
                        {
                            V--;
                            minV = min(V, minV);
                        }
                    }
                    else
                    {
                        V--;
                        minV = min(V, minV);
                    }

                    duplicate = false;
                }
                else
                {
                    if (V > 1)
                    {
                        V--;
                    }

                    duplicate = true;
                }
            }

            count += V;
        }

        if (minV <= 0)
        {
            count += sz * (1 - minV);
            prevMaxV += (1 - minV);
            V += (1 - minV);

            if (prevMaxV > V && V > 1)
            {
                count -= (prevMaxV - V) * (V - 1);
            }
        }

        return count;
    }
*/
};

int main()
{
    Solution sln;
    //vector<int> v;
    //srand(unsigned(time(0)));
    //initializeRandomVector(v, rand() % 20);
    //vector<int> v = {1};
    //vector<int> v = {2};
    //vector<int> v = {1, 1};
    //vector<int> v = {2, 2};
    //vector<int> v = {1, 2};
    //vector<int> v = {2, 1};
    //vector<int> v = {1, 1, 1};
    //vector<int> v = {1, 1, 2};
    //vector<int> v = {1, 2, 1};
    //vector<int> v = {1, 2, 2};
    //vector<int> v = {2, 1, 1};
    //vector<int> v = {2, 1, 2};
    //vector<int> v = {2, 2, 1};
    //vector<int> v = {2, 2, 2};
    //vector<int> v = {4, 2, 3, 4, 1};
    //vector<int> v = {1, 3, 4, 3, 2, 1};
    vector<int> v = {1, 4, 2, 2, 3};
    //vector<int> v = {636,6689,1960,1064,919,4453,7446,6987,4195,6804,8185,2177,6065,2701,5024,9056,5308,1778,4986,5989,3431,2775,4007,2562,517,8691,7906,5631,3142,2267,571,3779,8956,8884,1195,9876,3337,4994,6863,7532,1798,1400,6061,7863,454,1086,3271,5762,9216,8258,1751,2647,1033,5758,1562,7902,801,5820,9885,3944,8087,6809,7723,3396,5693,8918,3272,9030,3912,6487,2915,2062,4240,8976,9926,4694,6414,3197,456,5630,7807,8559,4630,5193,670,2544,3095,1471,4716,9333,5415,2804,6142,9490,6200,1835,8409,5824,7217,8673,8663,6484,736,2903,5461,662,3949,1875,211,757,3858,4371,5669,4840,9564,6339,3736,9011,7810,8452,8344,9578,7608,838,9068,160,2673,7477,2336,6243,2503,1000,2727,3239,255,4540,253,557,6416,6816,1314,6626,1187,6983,7818,7103,3322,7906,6115,7485,6358,811,7063,3967,1650,6131,479,675,9961,2816,6918,2464,3816,5998,5703,423,538,2308,980,3306,9124,8647,6284,6664,5630,454,3767,5305,8360,6234,9142,4719,3398,6205,5038,1400,8688,5517,2075,8649,8333,5346,7465,8501,7696,9520,8925,8234,1828,9905,1541,7305,8552
    printVector<int>(v);
    std::cout << sln.candy_buggy(v) << endl;
    return 0;
}
