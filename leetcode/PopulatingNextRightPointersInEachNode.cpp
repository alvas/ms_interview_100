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
        if (root == nullptr)
        {
            return;
        }

        if (root->left != nullptr)
        {
            root->left->next = root->right;
        }

        if (root->right != nullptr)
        {
            root->right->next = root->next != nullptr ? root->next->left : nullptr;
        }

        connect(root->left);
        connect(root->right);
    }

    void connect1(TreeLinkNode *root) {
        // assumption is perfect binary tree, so if either its children is NULL, both of them should be NULL.
        if (root == NULL || root->left == NULL || root->right == NULL)
        {
            return;
        }

        root->next = NULL;
        root->left->next = root->right;
        root->right->next = NULL;
        TreeLinkNode *p = root->left;
        TreeLinkNode *c = root->left->left;

        while (c != NULL)
        {
            TreeLinkNode *p1 = p;
            TreeLinkNode *c1 = c;

            while (p1 != NULL)
            {
                p1->left->next = p1->right;
                c1 = p1->right;
                p1 = p1->next;

                if (p1 != NULL)
                {
                    c1->next = p1->left;
                }
            }

            p = c;
            c = c->left;
        }
    }
};

int main()
{
    Solution sln;
    const int LOCAL_LENGTH = 7;
    //string a[LOCAL_LENGTH] = {"1"}; 
    //string a[LOCAL_LENGTH] = {"1", "2", "3"}; 
    string a[LOCAL_LENGTH] = {"1", "2", "3", "4", "5", "6", "7"};
    vector<string> v(a, a + LOCAL_LENGTH);
    TreeLinkNode *root = NULL;
    ReBuildTreeFromOrderLevel<TreeLinkNode>(v, root);
    //printTreePreorder<TreeLinkNode>(root);
    sln.connect(root);
    printTreeLinkOrderLevel(root);
    CleanUp2<TreeLinkNode>(root);
    return 0;
}
