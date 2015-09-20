#include <iostream>
#include <vector>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *p = l1, *q = l2, *curr = head;
        int carry = 0;

        while (p != NULL || q != NULL)
        {
            int x = (p != NULL) ? p->val : 0;
            int y = (q != NULL) ? q->val : 0;
            int digit = carry + x + y;
            carry = digit / 10;
            curr->next = new ListNode(digit % 10);
            curr = curr->next;

            if (p != NULL)
            {
                p = p->next;
            }

            if (q != NULL)
            {
                q = q->next;
            }
        }

        if (carry > 0)
        {
            curr->next = new ListNode(carry);
        }

        curr = head->next;
        delete head;
        return curr;
    }

    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        if (l1 == NULL || l2 == NULL)
        {
            return (l1 != NULL) ? l1 : l2;
        }

        // Be careful about the initial value of p1.
        // If l1 and l2 both have only 1 node, p1 should still be a valid value.
        ListNode *head = l1, *p1 = l1, *p2 = NULL;
        int carrier = 0;

        while (l1 != NULL && l2 != NULL)
        {
            int v = l1->val + l2->val + carrier;
            l1->val = v % 10;
            carrier = v / 10;
            p1 = l1;
            l1 = l1->next;
            p2 = l2;
            l2 = l2->next;
        }

        if (l1 != NULL)
        {
            while (l1 != NULL)
            {
                int v = l1->val + carrier;
                l1->val = v % 10;
                carrier = v / 10;
                p1 = l1;
                l1 = l1->next;
            }
        }
        else 
        {
            p1->next = l2;
            p2->next = NULL;

            while (l2 != NULL)
            {
                int v = l2->val + carrier;
                l2->val = v % 10;
                carrier = v / 10;
                p1 = l2;
                l2 = l2->next;
            }
        }

        if (carrier != 0)
        {
            p1->next = new ListNode(carrier);
        }

        return head;
    }
};

int main()
{
    Solution sln;
    ListNode *head = NULL, *l1 = NULL, *l2 = NULL;
    vector<int> v1, v2;

    int num = 0;
    cout << "Please enter number of digit of first input: ";
    cin >> num;

    for (int i = 0; i < num; ++i)
    {
        int t = 0;
        cout << "Please enter val: ";
        cin >> t;
        v1.push_back(t);
    }

    cout << "Please enter number of digit of second input: ";
    cin >> num;

    for (int i = 0; i < num; ++i)
    {
        int t = 0;
        cout << "Please enter val: ";
        cin >> t;
        v2.push_back(t);
    }

    initializeLinkList<ListNode>(v1, &l1);
    initializeLinkList<ListNode>(v2, &l2);
    head = sln.addTwoNumbers(l1, l2);
    printLinkList<ListNode>(head);
    destroyLinkList<ListNode>(l1);
    destroyLinkList<ListNode>(l2);
    return 0;
}
