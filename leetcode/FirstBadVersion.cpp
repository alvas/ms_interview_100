#include <cstdlib>
#include <iostream>

int badVersion = 0;

// Forward declaration of isBadVersion API.
 bool isBadVersion(int version)
{
    return badVersion <= version; 
}

 class Solution {
 public:
     int firstBadVersion(int n) {
         if (n <= 0)
         {
             return 0;
         }

         if (isBadVersion(1))
         {
             return 1;
         }
         else if (n == 1 || !isBadVersion(n))
         {
             return 0;
         }

         //long s = 1, e = n;
         int s = 1, e = n;

         while (s < e)
         {
             // be careful about overflow
             //long m = (s + e) >> 1;
             int m = (s >> 1) + (e >> 1);

             if (isBadVersion(m))
             {
                 e = m;
             }
             else
             {
                 s = m + 1;
             }
         }

         return e;
     }
 };

int main()
{
    Solution sln;
    int n = 0;

    for (int i = 0; i < 10; ++i)
    {
        n = i;
        std::cout << "total version is: " << n << std::endl;

        for (int j = 0; j <= i; ++j)
        {
            badVersion = j;
            std::cout << "bad version is: " << badVersion << std::endl;
            std::cout << "find first bad version: " << sln.firstBadVersion(n) << std::endl;
        }

        std::cout << std::endl;
    }
    
    n = 2126753390;
    badVersion = 1702766719;
    std::cout << "total version is: " << n << std::endl;
    std::cout << "bad version is: " << badVersion << std::endl;
    std::cout << "find first bad version: " << sln.firstBadVersion(n) << std::endl;

    //srand(time(NULL));
    //n = rand();
    //badVersion = rand() % n + 1;
    //std::cout << "total version is: " << n << std::endl;
    //std::cout << "bad version is: " << badVersion << std::endl;
    //std::cout << "find first bad version: " << sln.firstBadVersion(n) << std::endl;
    return 0;
}
