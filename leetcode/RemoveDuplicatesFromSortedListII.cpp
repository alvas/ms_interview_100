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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *c = head, *h = NULL, *prev = NULL;

        while (c != NULL)
        {
            bool isDuplicated = false;
            ListNode *p = c;

            // if c->val == c->next->val, delete c->next and attach the node after c->next to c->next
            while (c->next != NULL && c->next->val == c->val)
            {
                ListNode *tmp = c->next;
                c->next = tmp->next;
                delete tmp;
                isDuplicated = true;
            }

            if (isDuplicated)
            {
                // if c->val is duplicated, and c has previous node, attach the node after c to prev->next
                if (prev != NULL)
                {
                    prev->next = c->next;
                }

                // !! delete p must after c = c->next, otherwise c is the same as p, delete p wold make c invalid.
                c = c->next;
                delete p;
            }
            else
            {
                // get the new head node.
                if (h == NULL)
                {
                    h = p;
                }

                prev = p;
                c = c->next;
            }
        }

        return h;
    }
};

int main()
{
    Solution sln;
    const int LOCAL_LENGTH = 6;
    //int a[LOCAL_LENGTH] = {1, 2, 3, 3, 4, 4, 5};
    //int a[LOCAL_LENGTH] = {1};
    //int a[LOCAL_LENGTH] = {1, 2};
    //int a[LOCAL_LENGTH] = {1, 1};
    //int a[LOCAL_LENGTH] = {1, 2, 3};
    //int a[LOCAL_LENGTH] = {1, 1, 1};
    //int a[LOCAL_LENGTH] = {1, 1, 2};
    //int a[LOCAL_LENGTH] = {1, 2, 2};
    //int a[LOCAL_LENGTH] = {1, 1, 2, 2};
    //int a[LOCAL_LENGTH] = {1, 1, 2, 3};
    //int a[LOCAL_LENGTH] = {1, 1, 2, 3, 3};
    //int a[LOCAL_LENGTH] = {1, 1, 2, 2, 3};
    //int a[LOCAL_LENGTH] = {1, 1, 1, 2, 3};
    //int a[LOCAL_LENGTH] = {1, 2, 2, 2, 3};
    //int a[LOCAL_LENGTH] = {1, 2, 2, 3, 3};
    //int a[LOCAL_LENGTH] = {1, 2, 3, 3, 3};
    int a[LOCAL_LENGTH] = {1, 1, 2, 2, 3, 3};
    vector<int> v(a, a + LOCAL_LENGTH);
    ListNode *head = NULL;
    initializeLinkList<ListNode>(v, &head);
    head = sln.deleteDuplicates(head);
    printLinkList<ListNode>(head);
    return 0;
}
