#include <iostream>

#include "LinkList.h"
#include "Tree.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode *p = head;

        while (p != NULL)
        {
            p = p->next;
            n++;
        }

        return sortedListToBST(head, 0, n - 1);
    }

    TreeNode *sortedListToBST(ListNode *head, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }

        int mid = start + ((end - start) >> 1);
        TreeNode *leftChild = sortedListToBST(head, start, mid - 1);
        TreeNode *parent = new TreeNode (head->val);
        parent->left = leftChild;
        head = head->next;
        parent->right = sortedListToBST(head, mid + 1, end);
        return parent;
    }

    TreeNode* sortedListToBST1(ListNode* head) {
        TreeNode *root = NULL;

        if (head == NULL)
        {
            return root;
        }

        int len = getLength(head);
        root =  buildTree(head, len);
        return root;
    }

    int getLength(ListNode *head)
    {
        int len = 0;

        while (head != NULL)
        {
            len++;
            head = head->next;
        }

        return len;
    }

    ListNode *getMiddle(ListNode *head, int len)
    {
        ListNode *mid = head;

        if (head == NULL || len < 1)
        {
            return mid;
        }

        int half = (len - 1)  / 2;

        while (half--)
        {
            mid = mid->next;
        }

        return mid;
    }

    TreeNode *buildTree(ListNode *head, int len)
    {
        TreeNode *root = NULL;

        if (head == NULL || len == 0)
        {
            return root;
        }

        // Be careful about the lhalf and rhalf value.
        // Use simple example to calculate them, i.e. 1, 2, 3, 4, 5
        int lhalf = (len - 1) / 2, rhalf = len / 2;
        ListNode *mid = getMiddle(head, len);
        root = new TreeNode(mid->val);
        root->left = buildTree(head, lhalf);
        root->right = buildTree(mid->next, rhalf);
        return root;
    }
};

int main()
{
    Solution sln;
    vector<int> v;

    for (int i = 1; i < 15; ++i)
    {
        v.push_back(i);
        ListNode *head = NULL;
        initializeLinkList<ListNode>(v, &head);
        TreeNode *root = sln.sortedListToBST(head);
        destroyLinkList<ListNode>(head);
        printTreePreorder<TreeNode>(root);
        CleanUp2<TreeNode>(root);
    }

    return 0;
}
