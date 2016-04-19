#include <iostream>
#include <stack>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> stk;

        while (!stk.empty() || root)
        {
            if (root)
            {
                res.push_back(root->val);

                if (root->right)
                {
                    stk.push(root->right);
                }

                root = root->left;
            }
            else
            {
                root = stk.top();
                stk.pop();
            }
        }

        return res;
    }

    vector<int> preorderTraversal2(TreeNode* root) {
        vector<int> res;
        preorderTraversal_recursive(root, res);
        return res;
    }

    void preorderTraversal_recursive(TreeNode *root, vector<int> &res)
    {
        if (!root)
        {
            return;
        }

        res.push_back(root->val);
        preorderTraversal_recursive(root->left, res);
        preorderTraversal_recursive(root->right, res);
    }

    vector<int> preorderTraversal1(TreeNode* root) {
        vector<int> r;

        if (root == NULL)
        {
            return r;
        }

        stack<TreeNode *> s;
        s.push(root);
        r.push_back(root->val);
        TreeNode *prev = root;

        while (!s.empty())
        {
            TreeNode *top = s.top();

            if (top->left == NULL && top->right == NULL)
            {
                s.pop();
                prev = top;
            }
            else if (top->left != NULL && prev != top->left && prev != top->right)
            {
                s.push(top->left);
                // Be careful to push the top->left->value, not top->val
                r.push_back(top->left->val);
            }
            else if (top->right != NULL && prev != top->right)
            {
                s.push(top->right);
                // Be careful to push the top->right->value, not top->val
                r.push_back(top->right->val);
            }
            else
            {
                s.pop();
                prev = top;
            }
        }

        return r;
    }
};

int main()
{
    Solution sln;
    const int LOCAL_LENGTH = 13;
    string s[LOCAL_LENGTH] = {"30", "10", "50", "#", "#", "#", "20", "45", "#", "#", "35", "#", "#"};
    //string s[LOCAL_LENGTH] = {"1", "2"};
    //string s[LOCAL_LENGTH] = {"1", "#", "2"};
    //string s[LOCAL_LENGTH] = {"1"};
    //string s[LOCAL_LENGTH] = {"1", "2", "#", "3", "#", "4", "#"};
    //string s[LOCAL_LENGTH] = {"4", "#", "3", "#", "2", "#", "1"};
    //string s[LOCAL_LENGTH] = {"1", "3", "#", "#", "2"};
    //string s[LOCAL_LENGTH] = {"1", "#", "3", "2", "#"};
    vector<string> v(s, s + LOCAL_LENGTH);
    TreeNode *root = NULL;
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    vector<int> r = sln.preorderTraversal(root);
    printVector<int>(r);
    CleanUp2<TreeNode>(root);
    return 0;
}
