#include <iostream>
#include <vector>

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
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
    }

    /** @return the next smallest number */
    int next() {
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
int main()
{
    TreeNode *root = NULL;

    vector<string> v = 
    {
        "1", "#", "2", "#", "3", 
        "#", "4", "5", "#", "6", 
        "#", "7", "8", "9", "10", 
        "11", "#", "#", "#", "#", 
        "#", "12", "13", "#", "#", 
        "14"
    };

    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    printTreeLevelOrder<TreeNode>(root);
    BSTIterator i = BSTIterator(root);

    while (i.hasNext())
    {
        cout << i.next() << "\t";
    }

    cout << endl;
    CleanUp2<TreeNode>(root);
    return 0;
}
