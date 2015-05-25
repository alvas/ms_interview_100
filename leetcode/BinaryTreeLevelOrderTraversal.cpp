#include <iostream>
#include <queue>

#include "NormalData.h"
#include "Tree.h"

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > v;

        if (root != NULL)
        {
            vector<int> v1(1, root->val);
            queue<TreeNode *> q;
            q.push(root);
            v.push_back(v1);

            queue<TreeNode *> nextLevel;
            vector<int> v2;

            // using only one loop
            while (!q.empty())
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left != NULL)
                {
                    TreeNode *left = node->left;
                    nextLevel.push(left);
                    v2.push_back(left->val);
                }

                if (node->right != NULL)
                {
                    TreeNode *right = node->right;
                    nextLevel.push(right);
                    v2.push_back(right->val);
                }

                // checking q empty and then swap the queue
                // this implementation uses only 1 loop
                if (q.empty())
                {
                    if (!v2.empty())
                    {
                        v.push_back(v2);
                        v2.clear();
                    }

                    q.swap(nextLevel);
                }
            }
        }

        return v;
    }
};

int main()
{
    Solution sln;
    TreeNode *root = NULL;
    string s[7] = {"3", "9", "20", "#", "#", "15", "7"};
    vector<string> v(s, s + 7);
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    vector<vector<int> > r = sln.levelOrder(root);
    print2DVector<int>(r);
    return 0;
}

