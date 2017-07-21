#include <iostream>
#include <queue>
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;

        if (root) {
            q.push(root);
            q.push(nullptr);
        }

        vector<double> res;
        double sum = 0, count = 0;

        while (!q.empty()) {
            TreeNode *t = q.front();
            q.pop();

            if (!t) {
                res.push_back(sum / count);
                sum = count = 0;

                if (!q.empty()) {
                    q.push(nullptr);
                }
            }
            else {
                sum += t->val;
                count++;

                if (t->left) {
                    q.push(t->left);
                }

                if (t->right) {
                    q.push(t->right);
                }
            }

        }

        return res;
    }

    vector<double> averageOfLevels1(TreeNode* root) {
        queue<TreeNode*> q;

        if (root) {
            q.push(root);
        }

        vector<double> res;

        while (!q.empty()) {
            double sum = 0.0;
            int sz = q.size();
            queue<TreeNode*> tmp;

            while (!q.empty()) {
                TreeNode *ptr = q.front();
                q.pop();
                sum += ptr->val;

                if (ptr->left) {
                    tmp.push(ptr->left);
                }

                if (ptr->right) {
                    tmp.push(ptr->right);
                }
            }

            if (sz) {
                res.push_back(sum / sz);
            }

            q.swap(tmp);
        }

        return res;
    }
};

int main()
{
    Solution sln;
    TreeNode *root = nullptr;
    vector<string> s = {"3", "9", "20", "#", "#", "15", "7"};
    ReBuildTreeFromOrderLevel<TreeNode>(s, root);
    //printTreeLevelOrder<TreeNode>(root);
    vector<double> res = sln.averageOfLevels(root);
    printVector<double>(res);
    CleanUp2();
    return 0;
}
