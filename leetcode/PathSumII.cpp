#include <iostream>
#include <vector>

#include "NormalData.h"
#include "Tree.h"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<int> a;
        vector<vector<int> > v;
        findPath(root, sum, a, v);
        return v;
    }

    void findPath(TreeNode *root, int sum, vector<int> &a, vector<vector<int> > &v)
    {
        // Don't check sum < 0 here. Because the node can have negative value and the sum could be negative number also.
        if (root == NULL)
        {
            return;
        }
        else if (root->left == NULL && root->right == NULL)
        {
            sum -= root->val;

            if (sum == 0)
            {
                a.push_back(root->val);
                v.push_back(a);
                a.pop_back();
            }

            return;
        }

        // Be carefull about the substraction of sum here and the leave node in the else if condition above.
        sum -= root->val;
        a.push_back(root->val);

        if (root->left != NULL)
        {
            findPath(root->left, sum, a, v);
        }

        if (root->right != NULL)
        {
            findPath(root->right, sum, a, v);
        }

        a.pop_back();
        return;
    }
};

int main()
{
    Solution sln;
    int sum = 0;
    cout << "Please enter sum: ";
    cin >> sum;
    vector<string> s = {"-2", "#", "-3"};
    //vector<string> s = {"5", "4", "8", "11", "#", "13", "4", "7", "2", "#", "#", "5", "1"};
    vector<string> v(s, s + SIZE(s));
    TreeNode *root = NULL;
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    printTreePreorder<TreeNode>(root);
    vector<vector<int> > v1 = sln.pathSum(root, sum);
    print2DVector<int>(v1);
    CleanUp2(root);
    return 0;
}
