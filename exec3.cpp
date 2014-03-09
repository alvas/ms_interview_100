#include <iostream>

using namespace std;

int a[] = {1, -2, 3, 10, -4, 7, 2, -5};

int maxSubarray(int a[], int size)
{
    if (size < 0)
    {
        cerr << "The size of the array is negative!" << endl;
        exit(-1);
    };

    int max = a[0];
    int sum = 0;
    int index = 0;

    while (index < size)
    {
        sum += a[index++];

        if (max < sum)
        {
            max = sum;
        }
        else if (sum < 0)
        {
            sum = 0;
        }
    }

    return max;
}

int main()
{
    cout << maxSubarray(a, 8) << endl;;
    return 0;
}
