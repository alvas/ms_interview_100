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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > v;

        if (root == NULL)
        {
            return v;
        }

        // Be careful about the left/rigth direction.
        bool turnLeft = false;
        stack<TreeNode *> s;
        s.push(root);

        while (!s.empty())
        {
            stack<TreeNode *> s1;
            vector<int> a;

            while (!s.empty())
            {
                TreeNode *t = s.top();
                a.push_back(t->val);

                if (turnLeft)
                {
                    TreeNode *right = t->right;

                    if(right != NULL)
                    {
                        s1.push(right);
                    }

                    TreeNode *left = t->left;

                    if (left != NULL)
                    {
                        s1.push(left);
                    }
                }
                else
                {
                    TreeNode *left = t->left;

                    if (left != NULL)
                    {
                        s1.push(left);
                    }

                    TreeNode *right = t->right;

                    if(right != NULL)
                    {
                        s1.push(right);
                    }
                }

                s.pop();
            }

            v.push_back(a);
            a.clear();
            turnLeft = !turnLeft;

            s = s1;
        }

        return v;
    }
};

int main()
{
    Solution sln;
    string a[] = {"3", "9", "20", "#", "#", "15", "7"};
    vector<string> s(a, a + SIZE(a));
    TreeNode *root = NULL;
    ReBuildTreeFromOrderLevel<TreeNode>(s, root);
    printTreeLevelOrder<TreeNode>(root);
    vector<vector<int> > v = sln.zigzagLevelOrder(root);
    print2DVector<int>(v);
    CleanUp2(root);
    return 0;
}
