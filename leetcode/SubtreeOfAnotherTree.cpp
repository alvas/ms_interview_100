#include <cassert>
#include <iostream>

#include "Tree.h"

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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        // be careful about null pointer
        if (!s)
            return false;
        else if (isSameTree(s, t))
            return true;

        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool isSameTree(TreeNode *s, TreeNode *t) {
        if (!s && !t)
            return true;
        else if (!s && t)
            return false;
        else if (s && !t)
            return false;
        else if (s->val != t->val)
            return false;

        return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
};

int main()
{
    Solution sln;
    TreeNode *s= nullptr, *t = nullptr;
    //vector<string> v = {"3", "4", "5", "1", "2"};
    //vector<string> v = {"3", "4", "5", "1", "2", "#", "#", "#", "#", "0"};
    vector<string> v = {"1","#","1","#","1","#","1","#","1","#","1","#","1","#","1","#","1","#","1","#","1","2"};
    //vector<string> u = {"4", "1", "2"};
    vector<string> u = {"1","#","1","#","1","#","1","#","1","#","1","2"};
    ReBuildTreeFromOrderLevel<TreeNode>(v, s);
    ReBuildTreeFromOrderLevel<TreeNode>(u, t);
    cout << sln.isSubtree(s, t) << endl;
    CleanUp2(s);
    CleanUp2(t);
    return 0;
}
