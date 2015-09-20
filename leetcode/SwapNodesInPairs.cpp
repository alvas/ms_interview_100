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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = head;
        ListNode *prev = dummy;

        while (p != NULL && p->next != NULL)
        {
            ListNode *q = p->next;
            ListNode *r = p->next->next;
            prev->next = q;
            q->next = p;
            p->next = r;
            prev = p;
            p = r;
        }

        p = dummy->next;
        delete dummy;
        return p;
    }

    ListNode* swapPairs1(ListNode* head) {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *first = head, *second = head->next;
        ListNode *newHead = second, *tail = NULL;

        while (first->next != NULL)
        {
            // Be careful to link the previous node with the first and second
            if (tail != NULL)
            {
                tail->next = second;
                tail = first;
            }
            else
            {
                tail = first;
            }

            first->next = second->next;
            second->next = first;

            if (first->next != NULL)
            {
                first = first->next;
                second = first->next;
            }

        }

        return newHead;
    }
};

int main()
{
    Solution sln;
    const int LOCAL_LENGTH = 6;
    //int a[LOCAL_LENGTH] = {1};
    //int a[LOCAL_LENGTH] = {1, 2};
    //int a[LOCAL_LENGTH] = {1, 2, 3};
    //int a[LOCAL_LENGTH] = {1, 2, 3, 4};
    //int a[LOCAL_LENGTH] = {1, 2, 3, 4, 5};
    int a[LOCAL_LENGTH] = {1, 2, 3, 4, 5, 6};
    vector<int> v(a, a + LOCAL_LENGTH);
    ListNode *head = NULL;
    initializeLinkList<ListNode>(v, &head);
    ListNode *newHead = sln.swapPairs(head);
    printLinkList<ListNode>(newHead);
    destroyLinkList<ListNode>(newHead);
    return 0;
}
