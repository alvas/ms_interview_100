#include <iostream>
#include <stack>
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
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if (root != NULL)
        {
            TreeNode *node = root;

            while (node != NULL)
            {
                s.push(node);
                node = node->left;
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        int val = 0;

        if (!s.empty())
        {
            TreeNode *node = s.top();
            s.pop();
            val = node->val;
            node = node->right;

            while (node != NULL)
            {
                s.push(node);
                node = node->left;
            }
        }

        return val;
    }

    stack<TreeNode *> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) std::cout << i.next();
 */
int main()
{
    TreeNode *root = NULL;
    vector<string> v;

    //vector<string> a = {"1", "#", "2"};
    //vector<string> a = {"1", "#", "2", "3"};
    //vector<string> a = {"1", "2", "#", "3"};
    //vector<string> a = {"1", "2", "#", "#", "3"};
    //vector<string> a = {"1", "#", "2", "#", "3"};
    //vector<string> a = {"1", "#", "2", "#", "3", "#", "4", "5", "6"};

    vector<string> a = 
    {
        "8", "4", "12", "2", "6",
        "10", "14", "1", "3", "5",
        "7", "9", "11", "13", "15"
    };

    v.clear();
    v = a;
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    //printTreeLevelOrder<TreeNode>(root);
    printTreeInorder<TreeNode>(root);
    BSTIterator i = BSTIterator(root);

    while (i.hasNext())
    {
        std::cout << i.next() << "\t";
    }

    std::cout << endl;
    CleanUp2<TreeNode>(root);
    return 0;
}
