#include <iostream>
#include <vector>

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *newHead = NULL;

        if (head == NULL || k <= 1)
        {
            return head;
        }

        // Need prevTail to preserve connect the new list and the left.
        ListNode *prevTail = NULL, *tail = head, *node = head;

        while (tail != NULL)
        {
            int count = k;

            while (tail != NULL && count > 0)
            {
                tail = tail->next;
                count--;
            }

            if (tail == NULL && count > 0)
            {
                // Be careful when k is bitter than the length of the list
                if (newHead == NULL)
                {
                    newHead = head;
                }

                break;
            }

            ListNode *prev = NULL, *tmp = NULL;

            // Be careful to set the prev value
            while (node->next != tail)
            {
                if (prev == NULL)
                {
                    prev = node;
                    node = node->next;
                }
                else
                {
                    tmp = node->next;
                    node->next = prev;
                    prev = node;
                    node = tmp;
                }
            }

            node->next = prev;

            // Be careful to set the prevTail value and connect the new list and the left.
            if (newHead == NULL)
            {
                newHead = node;
                prevTail = head;
                prevTail->next = tail;
            }
            else
            {
                tmp = prevTail->next;
                tmp->next = tail;
                prevTail->next = node;
                prevTail = tmp;
            }

            node = tail;
        }

        return newHead;
    }
};

int main()
{
    Solution sln;
    ListNode *head = NULL;
    vector<int> v = {1};
    //vector<int> v = {1, 2};
    //vector<int> v = {1, 2, 3};
    //vector<int> v = {1, 2, 3, 4};
    //vector<int> v = {1, 2, 3, 4, 5};
    //vector<int> v = {1, 2, 3, 4, 5, 6};
    initializeLinkList<ListNode>(v, &head);
    printLinkList<ListNode>(head);

    int k = 0;
    std::cout << "Please enter k: ";
    cin >> k;

    head = sln.reverseKGroup(head,k);
    printLinkList<ListNode>(head);
    destroyLinkList<ListNode>(head);
    return 0;
}
