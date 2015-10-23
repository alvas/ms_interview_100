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
    // using O(n) space and sorting to find out the wrong elements
    void recoverTree_sort(TreeNode* root) {
        if (root == NULL)
        {
            return;
        }
        else if (root->left == NULL && root->right == NULL)
        {
            return;
        }

        vector<TreeNode *> v;
        buildInorderVector(root, v);
        vector<TreeNode *> copyV = v;
        sort(v.begin(), v.end(), myFunc);
        int sz = v.size();
        int a = -1, b = -1;

        for (int i = 0; i < sz; ++i)
        {
            if (v[i]->val != copyV[i]->val)
            {
                if (a == -1)
                {
                    a = i;
                }
                else
                {
                    b = i;
                    break;
                }
            }
        }

        swap(v[a]->val, v[b]->val);

        return;
    }

    void buildInorderVector(TreeNode *root, vector<TreeNode *> &v)
    {
        if (root == NULL)
        {
            return;
        }

        buildInorderVector(root->left, v);
        v.push_back(root);
        buildInorderVector(root->right, v);
    }

    static bool myFunc(TreeNode *a, TreeNode *b)
    {
        return a->val < b->val;
    }

    void recoverTree(TreeNode* root) {
        if (root == NULL)
        {
            return;
        }
        else if (root->left == NULL && root->right == NULL)
        {
            return;
        }

        TreeNode *a = NULL, *b = NULL, *prev = NULL;
        forwardFindWrongNode(root, prev, a);
        prev = NULL;
        backwardFindWrongNode(root, prev, b);

        swap(a->val, b->val);

        return;
    }

    void forwardFindWrongNode(TreeNode *root, TreeNode *&prev, TreeNode *&a)
    {
        if (root == NULL || a != NULL)
        {
            return;
        }

        forwardFindWrongNode(root->left, prev, a);

        if (prev != NULL && root->val < prev->val)
        {
            a = prev;
            return;
        }

        prev = root;

        forwardFindWrongNode(root->right, prev, a);

        return;
    }

    void backwardFindWrongNode(TreeNode *root, TreeNode *&prev, TreeNode *&b)
    {
        if (root == NULL || b != NULL)
        {
            return;
        }

        backwardFindWrongNode(root->right, prev, b);

        if (prev != NULL && root->val > prev->val)
        {
            b = prev;
            return;
        }

        prev = root;

        backwardFindWrongNode(root->left, prev, b);

        return;
    }
};

int main()
{
    Solution sln;
    //vector<string> s = {"0"};
    //vector<string> s = {"0", "1"};
    //vector<string> s = {"2", "#", "3", "1"};
    //vector<string> s = {"3", "1", "2"};
    vector<string> s = {"8", "2", "6", "0", "4", "7", "9", "#", "#", "3", "5"};
    TreeNode *root = NULL;
    ReBuildTreeFromOrderLevel<TreeNode>(s, root);
    printTreeLevelOrder<TreeNode>(root);
    sln.recoverTree(root);
    //sln.recoverTree_sort(root);
    printTreeLevelOrder<TreeNode>(root);
    CleanUp2(root);
    return 0;
}
