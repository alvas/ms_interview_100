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
    vector<int> v;

    for (int i = 1; i <= 1; ++i)
    {
        v.push_back(i);
    }

    ListNode *head = NULL;
    initializeLinkList<ListNode>(v, &head);
    head = sln.oddEvenList(head);
    printLinkList<ListNode>(head);
    destroyLinkList<ListNode>(head);
    return 0;
}
