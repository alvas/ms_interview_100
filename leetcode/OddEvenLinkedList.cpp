#include <iostream>

#include "LinkList.h"

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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *odd = head, *even = head->next, *evenHead = head->next;

        while (odd != NULL && even != NULL)
        {
            odd->next = even->next;

            // be careful about the NULL, don't overwrite the odd,
            // because we need to set odd->next = evenHead later.
            if (even->next != NULL)
            {
                odd = even->next;
                even->next = odd->next;
                even = odd->next;
            }
            else
            {
                // even number of nodes. Get to the end of odd list.
                break;
            }
        }

        // need to be careful before.
        odd->next = evenHead;

        return head;
    }

    ListNode* oddEvenList1(ListNode* head) {
        ListNode *newOdd = head, *odd = head, *newEven = NULL, *even = NULL;

        if (head != NULL)
        {
            head = head->next;
            even = head;
            newEven = head;

            // Be careful for null pointer when there is only one node.
            if (head != NULL)
            {
                head = head->next;
            }
        }

        while (head != NULL)
        {
            odd->next = head;
            odd = odd->next;
            head = head->next;

            if (head != NULL)
            {
                even->next = head;
                even = even->next;
                head = head->next;
            }
            else
            {
                even->next = NULL;
            }
        }

        if (odd != NULL)
        {
            odd->next = newEven;
        }

        return newOdd;
    }
};

int main()
{
    Solution sln;
    const int N = 7;
    vector<int> v;

    for (int i = 1; i <= N; ++i)
    {
        v.push_back(i);
        ListNode *head = NULL;
        initializeLinkList<ListNode>(v, &head);
        head = sln.oddEvenList(head);
        printLinkList<ListNode>(head);
        destroyLinkList<ListNode>(head);
    }

    return 0;
}
