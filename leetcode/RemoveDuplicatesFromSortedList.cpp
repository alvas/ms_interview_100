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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *p1 = head, *p2 = head->next;

        while (p1 && p2)
        {
            if (p1->val == p2->val)
            {
                p1->next = p2->next;
                delete p2;
                p2 = p1->next;
            }
            else
            {
                p1 = p2;
                p2 = p1->next;
            }
        }

        return head;
    }

    // May need to improve.
    ListNode *deleteDuplicates1(ListNode *head) {
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
    std::vector<int> va = {1, 1, 2, 3, 4, 4, 5, 5};
    initializeLinkList<ListNode>(va, &head);
    head = sln.deleteDuplicates(head);
    printLinkList<ListNode>(head);
    destroyLinkList<ListNode>(head);
    return 0;
}

