#include <iostream>

#include "Tree.h"

using namespace std;

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
    }
};

int main()
{
    Solution sln;
    const int LOCAL_LENGTH = 7;
    string a[LOCAL_LENGTH] = {"1", "2", "3", "4", "5", "6", "7"};
    vector<string> v(a, a + LOCAL_LENGTH);
    TreeLinkNode *root = NULL;
    ReBuildTreeFromOrderLevel<TreeLinkNode>(root, v);
    sln.connect(root);
    CleanUp2<TreeLinkNode>(root);
    return 0;
}
