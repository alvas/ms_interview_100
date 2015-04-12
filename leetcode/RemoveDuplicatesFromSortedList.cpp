#include <iostream>

#include "LinkList.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // May need to improve.
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL)
        {
            return head;
        }

        ListNode *node = head, *prev = NULL;

        while (node != NULL)
        {
            if (prev != NULL && prev->val == node->val)
            {
                ListNode *cur = node;
                node = node->next;
                delete cur;
                prev->next = node;
            }
            else
            {
                prev = node;
                node = node->next;
            }
        }

        return head;
    }
};

int main()
{
    Solution sln;
    ListNode *head = NULL;
    const int lengthA = 6;
    int A[lengthA] = {1, 2, 3, 4, 4, 5};
    vector<int> va(A, A + lengthA);
    initializeLinkList<ListNode>(va, &head);
    head = sln.deleteDuplicates(head);
    printLinkList<ListNode>(head);
    destroyLinkList<ListNode>(head);
    return 0;
}

