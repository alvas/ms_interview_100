#include <iostream>
#include <stack>
#include <queue>
#include <vector>

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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> v;

        if (!root)
        {
            return v;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            queue<TreeNode *> p;
            vector<int> u;

            while (!q.empty())
            {
                TreeNode *t = q.front();
                q.pop();
                u.push_back(t->val);

                // made a stupid mistake here checking not null by !t->left
                if (t->left)
                {
                    p.push(t->left);
                }

                if (t->right)
                {
                    p.push(t->right);
                }
            }

            v.push_back(u);
            q.swap(p);
        }

        std::reverse(v.begin(), v.end());
        return v;
    }

    // Need to improve performance.
    vector<vector<int> > levelOrderBottom1(TreeNode *root) {
        vector<vector<int> > r;

        if (root != NULL)
        {
            vector<int> v(1, root->val);
            stack<vector<int> > s;
            queue<TreeNode *> q;
            s.push(v);
            q.push(root);
            
            // using two variables to save number in the current level
            // and next level
            int numCurrentLevel = 1, numNextLevel = 0;
            vector<int> v1;

            while (!q.empty())
            {
                TreeNode *node = q.front();
                q.pop();
                numCurrentLevel--;

                if (node->left != NULL)
                {
                    TreeNode *left = node->left;
                    v1.push_back(left->val);
                    q.push(left);
                    numNextLevel++;
                }

                if (node->right != NULL)
                {
                    TreeNode *right = node->right;
                    v1.push_back(right->val);
                    q.push(right);
                    numNextLevel++;
                }

                if (numCurrentLevel == 0)
                {
                    // Be careful when v1 is empty!!
                    if (v1.size() > 0)
                    {
                        s.push(v1);
                        v1.clear();
                    }

                    numCurrentLevel = numNextLevel;
                    numNextLevel = 0;
                }
            }


            while (!s.empty())
            {
                r.push_back(s.top());
                s.pop();
            }
        }

        return r;
    }
};

int main()
{
    Solution sln;
    TreeNode *root = NULL;
    vector<string> v = {"3", "9", "20", "#", "#", "15", "7"};
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    vector<vector<int> > r = sln.levelOrderBottom(root);
    print2DVector<int>(r);
    return 0;
}
