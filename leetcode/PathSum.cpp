#include <iostream>
#include <queue>
#include <stack>

#include "../Tree.h"

using namespace std;

const int TREELEN_PATHSUM = 9;

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {

        if (root == NULL)
        {
            cout << "root == NULL" << endl;
            return false;
        }
        else if (root->left == NULL && root->right == NULL)
        {
            sum -= root->val;

            if (sum == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        sum -= root->val;
        bool hasSum = false;
        
        if (root->left != NULL)
        {
            hasSum = hasPathSum(root->left, sum);
        }

        if (root->right != NULL && !hasSum)
        {
            hasSum = hasPathSum(root->right, sum);
        }

        return hasSum;
    }
};

int main()
{
    /*
    int szPreOrder[TREELEN_PATHSUM] = {5, 4, 11, 7, 2, 8, 13, 4, 1};
    int szInOrder[TREELEN_PATHSUM] = {7, 11, 2, 4, 5, 13, 8, 4, 1};
    int szPostOrder[TREELEN_PATHSUM] = {7, 2, 11, 4, 13, 1, 4, 8, 5};

    int szPreOrder[TREELEN_PATHSUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int szInOrder[TREELEN_PATHSUM] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    int szPreOrder[TREELEN_PATHSUM] = {4, 4, 4, 4, 4, 4, 4, 4, 4};
    int szInOrder[TREELEN_PATHSUM] = {4, 4, 4, 4, 4, 4, 4, 4, 4};

    int szPreOrder[TREELEN_PATHSUM] = {1, 2, 3};
    int szInOrder[TREELEN_PATHSUM] = {2, 1, 3};
    */

    int szPreOrder[TREELEN_PATHSUM] = {1, 2, 3, 4, 5, 6, 7};
    int szInOrder[TREELEN_PATHSUM] = {3, 2, 4, 1, 6, 5, 7};

    TreeNode *root = NULL;
    ReBuildTreeFromPreIn2(szPreOrder, szInOrder, TREELEN_PATHSUM, root);
    //ReBuildTreeFromPrePost(szPreOrder, szPostOrder, TREELEN_PATHSUM, root);
    //ReBuildTreeFromInPost(szInOrder, szPostOrder, TREELEN_PATHSUM, root);

    cout << "Please enter the sum: ";
    int num = 0;
    cin >> num;

    Solution sln;
    cout << sln.hasPathSum(root, num) << endl;
    CleanUp2(root);
    return 0;
}

