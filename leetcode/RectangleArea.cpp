#include <iostream>

using namespace std;

class Solution {
public:
    // This problem has issue, because the rectanble should be defined by its bottom left corner and top right corner. And if it is true, it doesn't require to use abs to calculate the width or length. But the test data implies that the definition is not accurate.
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = abs(C - A) * abs(D - B);
        int area2 = abs(G - E) * abs(H - F);

        if ((E < A && G < A) || (E > C && G > C) ||
            (F < B && H < B) || (F > D && H > D))
        {
            return area1 + area2;
        }

        int X1 = A < E ? E : A;
        int X2 = C < G ? C : G;

        int Y1 = B < F ? F : B;
        int Y2 = D < H ? D : H;

        int area3 = abs(X2 - X1) * abs(Y2 - Y1);

        return area1 + area2 - area3;
    }
};

int main()
{
    Solution sln;
    //int A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2;
    int A = -2, B = -2, C = 2, D = 2, E = -3, F = 3, G = -4, H = 4;
    cout << sln.computeArea(A, B, C, D, E, F, G, H) << endl;
    return 0;
}
