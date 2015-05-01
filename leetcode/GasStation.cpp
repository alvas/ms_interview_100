#include <iostream>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    // This problem is really tircky. Need to think about it more carefully.
    // The key of this problem is that only if sum >= 0, it can finish the trip.
    // And the last index which has local accumulated sum negative would indicate that
    // from the next node after this last index, all accumulated sum is non-netative.
    // any node before the last node which causes local accumulate sum negative and breaks
    // the trip.
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int N = gas.size();

        int sum = 0, tmpSum = 0, index = -1;

        for (int i = 0; i < N; ++i)
        {
            int diff = gas[i] - cost[i];
            sum += diff;
            tmpSum += diff;

            // if all 0, {0, 0, 0, 0, 0}, this would not be true
            // and it takes care of this case.
            if (tmpSum < 0)
            {
                tmpSum = 0;
                index = i;
            }
        }

        if (sum < 0)
        {
            return -1;
        }
        else
        {
            // remember to return the index one after it.
            return index + 1;
        }
    }

    int canCompleteCircuit_awkward(vector<int>& gas, vector<int>& cost) {
        int N = gas.size();

        // Greedy, use min as heuristic:w
        vector<int> diffs;
        int min = 0, minIndex = -1;
        int sum = 0;

        for (int i = 0; i < N; ++i)
        {
            int diff = gas[i] - cost[i];
            diffs.push_back(diff);
            sum += diff;

            // initial value for min
            if (i == 0)
            {
                min = diff;

                // if gas[i] = 0, don't set minIndex
                if (gas[i] != 0)
                {
                    minIndex = i;
                }
            }

            // It is tricky here. Don't use >=, otherwise {0, 0, 0, 0, 0}
            // would set minIndex = 4.
            if (min > diff)
            {
                min = diff;
                minIndex = i;
            }
        }

        int index = -1;

        // if sum < 0, no solution
        // if gas[0] = 0 and no other diff is smaller than 0, then it means all 0
        if (sum >= 0 && minIndex != -1)
        {
            bool enough = true;

            // Don't use minIndex++, because it needs to be module by N
            minIndex = (minIndex + 1) % N;

            // find the nonnegative start point
            while (diffs[minIndex] < 0)
            {
                minIndex = (minIndex + 1) % N;
            }

            for (int i = 0; i < N; ++i)
            {
                sum += diffs[(i + minIndex) % N];

                if (sum < 0)
                {
                    enough = false;
                    break;
                }
            }

            if (enough)
            {
                // Be careful about the index which needs to module N.
                index = (minIndex) % N;
            }
        }

        return index;
    }

    int canCompleteCircuit_slow2(vector<int>& gas, vector<int>& cost) {
        int N = gas.size();

        // Compute the difference betweeen gas[i] and cost[i]
        for (int i = 0; i < N; ++i)
        {
            gas[i] -= cost[i];
        }

        int index = -1;

        for (int i = 0; i < N; ++i)
        {
            if (gas[i] < 0)
            {
                continue;
            }

            int sum = 0, j = 0;

            for ( ; j < N; ++j)
            {
                sum += gas[(i + j) % N];

                if (sum < 0)
                {
                    break;
                }
            }

            if (j >= N)
            {
                index = i;
                break;
            }
        }

        return index;
    }

    int canCompleteCircuit_slow(vector<int>& gas, vector<int>& cost) {
        int N = gas.size();
        int index = 0;
        bool finished = true;

        for (int i = 0; i < N; ++i)
        {
            int sumGas = 0, sumCost = 0;
            index = i;
            finished = true;

            for (int j = 0; j < N; ++j)
            {
                sumGas += gas[(i + j) % N];
                sumCost += cost[(i + j) % N];

                // if the accumulated cost is more than gas, then it can't finish.
                if (sumGas < sumCost)
                {
                    finished = false;
                    break;
                }
            }

            if (finished)
            {
                break;
            }
        }

        if (!finished)
        {
            index = -1;
        }

        return index;
    }
};

int main()
{
    Solution sln;
    //const int local_length = 5;
    //int a[local_length] = {6, 1, 4, 3, 5}, b[local_length] = {3, 8, 2, 4, 2};
    //int a[local_length] = {0, 0, 0, 0, 0}, b[local_length] = {0, 0, 0, 0, 0};
    //int a[local_length] = {1, 2, 3, 4, 5}, b[local_length] = {3, 4, 5, 1, 2};
    //const int local_length = 1;
    //int a[local_length] = {5}, b[local_length] = {4};
    //int a[local_length] = {3}, b[local_length] = {4};
    //int a[local_length] = {2}, b[local_length] = {2};
    const int local_length = 7;
    int a[local_length] = {2, 0, 1, 2, 3, 4, 0}, b[local_length] = {0, 1, 0, 0, 0, 0, 11};
    vector<int> gas(a, a + local_length), cost(b, b + local_length);
    //initializeRandomVector(gas, 400);
    //initializeRandomVector(cost, 400);
    printVector<int>(gas);
    cout << endl;
    printVector<int>(cost);
    cout << sln.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
