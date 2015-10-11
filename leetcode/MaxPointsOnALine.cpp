#include <iostream>
#include <map>
#include <utility>
#include <vector>

#include "Point.h"
#include "NormalData.h"

using namespace std;

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    static bool myFunc(Point &a, Point &b)
    {
        if (a.x < b.x)
        {
            return true;
        }
        else if (a.x > b.x)
        {
            return false;
        }
        else
        {
            if (a.y < b.y)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    // My solution passes by lucky. Thanks God.
    int maxPoints(vector<Point>& points) {
        int sz = points.size();

        if (sz <= 2)
        {
            return sz;
        }

        int count = 0;

        // sorting, so we can skip duplicate points and make thing easier
        sort(points.begin(), points.end(), myFunc);

        for (int i = 0; i < sz; ++i)
        {
            map<double, int> m;
            Point a = points[i];
            int verticalLine = 0;
            int samePoint = 1;

            for (int j = i + 1; j < sz; ++j)
            {
                Point b = points[j];

                // skip duplicate points
                while (a.x == b.x && a.y == b.y)
                {
                    j++;
                    samePoint++;

                    if (j < sz)
                    {
                        b = points[j];
                    }
                    else
                    {
                        break;
                    }
                }

                if (j >= sz)
                {
                    count = max(count, samePoint);
                    break;
                }

                b = points[j];

                if (a.x != b.x)
                {
                    double x = a.x - b.x, y = a.y - b.y;
                    double slop = y / x;

                    if (m.find(slop) == m.end())
                    {
                        m.insert(make_pair(slop, samePoint + 1));
                    }
                    else
                    {
                        int oldC = m[slop];
                        m[slop] = oldC + 1;
                    }

                    count = max(count, m[slop]);
                }
                else
                {
                    verticalLine++;
                    count = max(count, samePoint + verticalLine);
                }
            }

            // skip duplicate points
            i += (samePoint - 1);
        }

        return count;
    }
};

int main()
{
    Solution sln;
    vector<int> a[2] = {{0, -12}, {5, 2}, {2, 5}, {0, -5}, {1, 5}, {2, -2}, {5, -4}, {3, 4}, {-2, 4}, {-1, 4}, {0, -5}, {0, -8}, {-2, -1}, {0, -11}, {0, -9}};
    vector<Point> points;

    for (int i = 0; i < SIZE(a); ++i)
    {
        Point p(a[i][0], a[i][1]);
        points.push_back(p);
    }

    //srand(unsigned(time(0)));

    //for (int i = 0; i < 50; ++i)
    //{
        //Point p(rand() % 500, rand() % 500);
        //points.push_back(p);
    //}

    //Point p1(1, 2);
    //Point p2(2, 4);
    //Point p3(3, 6);
    //Point p4(4, 5);
    //Point p1(2, 2);
    //Point p2(2, 4);
    //Point p3(2, 6);
    //Point p4(4, 5);
    //Point p1(0, 0);
    //Point p2(1, 1);
    //Point p3(0, 0);
    //points.push_back(p1);
    //points.push_back(p2);
    //points.push_back(p3);
    //points.push_back(p4);

    //for (vector<Point>::iterator itr = points.begin();
         //itr != points.end(); ++itr)
    //{
        //cout << itr->x << "\t" << itr->y << endl;
    //}

    cout << sln.maxPoints(points) << endl;

    for (vector<Point>::iterator itr = points.begin();
         itr != points.end(); ++itr)
    {
        cout << itr->x << "\t" << itr->y << endl;
    }

    return 0;
}
