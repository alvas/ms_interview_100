#include <iostream>

#include "LinkList.h"
#include "NormalData.h"

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
    ListNode* reverseBetween1(ListNode* head, int m, int n) {
        if (m < 1 || m >= n || !head)
        {
            return head;
        }

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;

        for (int i = 0; i < m - 1; ++i)
        {
            head = head->next;
        }

        ListNode *pre = head->next, *cur = pre->next;

        for (int i = 0; i < n - m; ++i)
        {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        head->next->next = cur;
        head->next = pre;
        head = dummy->next;
        delete dummy;
        return head;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *newHead = head;

        if (newHead == NULL || m == n)
        {
            return newHead;
        }

        // reverse node start in the middle of the list
        if (m != 1)
        {
            ListNode *tail1 = head;

            for (int i = 0; i < m - 2; ++i)
            {
                tail1 = tail1->next;
            }
            
            ListNode *prev = tail1->next;
            ListNode *start = prev->next;
            ListNode *next = NULL;

            // reverse nodes in the middle of the list 
            if (start != NULL)
            {
                next = start->next;

                // Be carefull about the start and next pointer when they become NULL
                for (int i = 0; i < n - m && start != NULL; ++i)
                {
                    start->next = prev;
                    prev = start;
                    start = next;

                    if (next != NULL)
                    {
                        next = next->next;
                    }
                }

                tail1->next->next = start;
                tail1->next = prev;
            }
            else
            {
                // reverse all node execpt the last one
                prev = head;
                start = prev->next;

                if (start != NULL)
                {
                    next = start->next;
                }

                prev->next = NULL;

                // Be carefull about the start and next pointer when they become NULL
                while (start != NULL)
                {
                    start->next = prev;
                    prev = start;
                    start = next;

                    if (next != NULL)
                    {
                        next = next->next;
                    }
                }

                newHead = prev;
            }
        }
        else
        {
            // reverse node from the first one
            ListNode *prev = head;
            ListNode *start = prev->next;
            ListNode *next = NULL;

            if (start != NULL)
            {
                next = start->next;
            }

            prev->next = NULL;

            // Be carefull about the start and next pointer when they become NULL
            for (int i = 0; i < n - 1 && start != NULL; ++i)
            {
                start->next = prev;
                prev = start;
                start = next;

                if (next != NULL)
                {
                    next = next->next;
                }
            }

            newHead = prev;
            head->next = start;
        }

        return newHead;
    }
};

int main()
{
    Solution sln;
    vector<int> v = {1, 2, 3, 4, 5};
    //vector<int> v = {};
    //vector<int> v = {1};
    //vector<int> v = {1, 2};
    //vector<int> v = {1, 2, 3};
    int m = 0, n = 0;
    std::cout << "Please enter m[1, " << v.size() << "]: ";
    cin >> m;
    std::cout << "Please enter n[" << m << ", " << v.size() << "]: ";
    cin >> n;
    ListNode *head = NULL;
    initializeLinkList<ListNode>(v, &head);
    printLinkList<ListNode>(head);
    head = sln.reverseBetween(head, m, n);
    printLinkList<ListNode>(head);
    destroyLinkList<ListNode>(head);
    return 0;
}
