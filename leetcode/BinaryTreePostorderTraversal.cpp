#include <iostream>
#include <stack>

#include "Tree.h"
#include "NormalData.h"

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *prev = root;

        while (!stk.empty() || root)
        {
            if (root)
            {
                stk.push(root);
                root = root->left;
            }
            else
            {
                root = stk.top();

                if (root->right && root->right != prev)
                {
                    root = root->right;
                }
                else
                {
                    stk.pop();
                    res.push_back(root->val);
                    prev = root;
                    root = NULL;
                }
            }
        }

        return res;
    }

    vector<int> postorderTraversal2(TreeNode* root) {
        vector<int> res;
        postorderTraversal_recursive(root, res);
        return res;
    }

    void postorderTraversal_recursive(TreeNode *root, vector<int> &res)
    {
        if (!root)
        {
            return;
        }

        postorderTraversal_recursive(root->left, res);
        postorderTraversal_recursive(root->right, res);
        res.push_back(root->val);
    }

    vector<int> postorderTraversal1(TreeNode* root) {
        vector<int> v;

        if (root == NULL)
        {
            return v;
        }

        stack<TreeNode *> s;
        s.push(root);
        //std::cout << "pushing " << root->val << endl;
        TreeNode *prev = NULL;

        while (!s.empty())
        {
            TreeNode *top = s.top();

            // After we pop the left child, the top we need to check whether prev != top->left to avoid push left child to the stack again.
            // Be careful when the root doesn't have a right child, at this time, prev == NULL and prev == top->right, otherwise, the left child could not be inserted correctly
            // And if a child has both left and right child, after we pop the right child, we need to check prev != top->right, otherwise, it will push the right child to the stack again and cause infinite loop.
            if (top->left != NULL && prev != top->left && (prev == NULL || prev != top->right))
            {
                s.push(top->left);
                //std::cout << "pushing " << top->val << endl;
            }
            else if (top->right != NULL && prev != top->right)
            {
                s.push(top->right);
                //std::cout << "pushing " << top->val << endl;
            }
            else
            {
                v.push_back(top->val);
                prev = top;
                s.pop();
            }
        }

        return v;
    }
};

int main()
{
    Solution sln;
    const int LOCAL_LENGTH = 13;
    string s[LOCAL_LENGTH] = {"30", "10", "50", "#", "#", "#", "20", "45", "#", "#", "35", "#", "#"};
    //string s[LOCAL_LENGTH] = {"1", "2"};
    vector<string> v(s, s + LOCAL_LENGTH);
    printVector<string>(v);
    TreeNode *root = NULL;
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    vector<string> v2;
    BuildOrderLevelVector(root, v2);
    printVector<string>(v2);
    vector<int> r = sln.postorderTraversal(root);
    printVector<int>(r);
    CleanUp2<TreeNode>(root);
    return 0;
}
