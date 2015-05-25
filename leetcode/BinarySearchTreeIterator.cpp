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
    const int LOCAL_LENGTH = 26;
    TreeNode *root = NULL;
    vector<string> v;

    //string a[LOCAL_LENGTH] = {"1", "#", "2"};
    //string a[LOCAL_LENGTH] = {"1", "#", "2", "3"};
    //string a[LOCAL_LENGTH] = {"1", "2", "#", "3"};
    //string a[LOCAL_LENGTH] = {"1", "2", "#", "#", "3"};
    //string a[LOCAL_LENGTH] = {"1", "#", "2", "#", "3"};
    //string a[LOCAL_LENGTH] = {"1", "#", "2", "#", "3", "#", "4", "5", "6"};

    string a[LOCAL_LENGTH] = 
    {
        "8", "4", "12", "2", "6",
        "10", "14", "1", "3", "5",
        "7", "9", "11", "13", "15"
    };

    v.clear();
    v.assign(a, a + LOCAL_LENGTH);
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
