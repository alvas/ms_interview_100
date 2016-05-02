#include <cassert>
#include <iostream>

#include "NormalData.h"
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

        TreeLinkNode *p = root->next;

        while (p != nullptr)
        {
            if (p->left != nullptr)
            {
                p = p->left;
                break;
            }

            if (p->right != nullptr)
            {
                p = p->right;
                break;
            }

            p = p->next;
        }

        if (root->left != nullptr)
        {
            root->left->next = root->right ? root->right : p;
        }

        if (root->right != nullptr)
        {
            root->right->next = p;
        }

        // process right child first
        connect(root->right);
        connect(root->left);
    }

    void connect1(TreeLinkNode *root) {
        if (root == NULL)
        {
            return;
        }
        
        // Think about it clear what variables are needed and the change of value cur.
        TreeLinkNode *cur = root;
        TreeLinkNode *head = findHead(cur);
        TreeLinkNode *prev = head;

        // Be careful when the root node only has right child. In this case, cur would be NULL.
        while (head != NULL && cur != NULL)
        {
            TreeLinkNode *next = findNext(cur, prev);

            while (next != NULL)
            {
                prev->next = next;
                prev = next;
                next = findNext(cur, prev);
            }

            cur = head;
            head = findHead(cur);
            prev = head;
        }
    }

    TreeLinkNode *findHead(TreeLinkNode *&cur)
    {
        TreeLinkNode *head = NULL;

        while (cur != NULL)
        {
            head = cur->left;

            if (head != NULL)
            {
                break;
            }

            head = cur->right;

            // When find the head, don't move the cur.
            if (head != NULL)
            {
                break;
            }

            cur = cur->next;
        }

        return head;
    }

    TreeLinkNode *findNext(TreeLinkNode *&cur, TreeLinkNode *begin)
    {
        TreeLinkNode *next = NULL;

        // Make the checking simple by handling left and right explicitly.
        if (begin == cur->left)
        {
            next = cur->right;
        }
        else if (begin == cur->right)
        {
            cur = cur->next;

            // Be careful about the cur == NULL here. When begin is already the last node in one level, then cur would be NULL.
            if (cur != NULL)
            {
                next = cur->left;
            }
        }

        // Be careful about next == NULL
        while (cur != NULL && next == NULL)
        {
            next = cur->right;

            if (next != NULL)
            {
                break;
            }

            cur = cur->next;

            // Be careful when cur become NULL
            if (cur != NULL)
            {
                next = cur->left;
            }
        }

        return next;
    }
};

int main()
{
    Solution sln;
    //vector<string> v = {"1", "2"};
    //vector<string> v = {"1", "#", "2"};
    vector<string> v = {"7", "-10", "2", "-4", "3", "-8", "#", "#", "#", "#", "-1", "11"};
    //vector<string> v = {"1", "2", "3", "4", "5", "#", "7"};
    TreeLinkNode *root = NULL;
    ReBuildTreeFromOrderLevel<TreeLinkNode>(v, root);
    //printTreePreorder<TreeLinkNode>(root);
    sln.connect(root);
    printTreeLinkOrderLevel(root);
    CleanUp2<TreeLinkNode>(root);
    return 0;
}
