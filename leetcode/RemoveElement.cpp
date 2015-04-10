#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0, j = n - 1;

        // Be carefull about the equal condition here!!
        while (i <= j)
        {
            while (A[i] != elem && i <= j)
            {
                i++;
            }

            if (i > j)
            {
                break;
            }

            while (A[j] == elem && i <= j)
            {
                j--;
            }

            if (i > j)
            {
                break;
            }

            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }


        return i;
    }
};

int main()
{
    Solution sln;
    int A[500];
    int n = 0, elem = 0;
    string s;

    cout << "Please enter numbers: ";
    getline(cin, s);

    cout << "Please enter elem: ";
    cin >> elem;

    istringstream str(s);
    string sub;

    while (getline(str, sub, ' '))
    {
        A[n++] = atoi(sub.c_str());
    }

    cout << sln.removeElement(A, n, elem) << endl;
    return 0;
}
