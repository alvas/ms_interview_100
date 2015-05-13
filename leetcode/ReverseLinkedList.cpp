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
    ListNode* reverseList_recursive(ListNode* head) {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *next = head->next;
        
        // break the next link, set the next pointer of the first node to NULL
        // avoid cycle.
        head->next = NULL;

        // recursively get the tail and return it.
        // IMPORTANT!! Need to do this before we modify the next pointer.
        ListNode *ret = reverseList_recursive(next);

        next->next = head;
        return ret;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
        {
            return head;
        }

        ListNode *prev = NULL, *cur = head, *next = head->next;

        while (next != NULL)
        {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next->next;
        }

        cur->next = prev;

        return cur;
    }
};

int main()
{
    Solution sln;
    ListNode *head = NULL;
    const int LOCAL_LENGTH = 6;
    int a[LOCAL_LENGTH] = {1, 2, 3, 4, 5, 6};
    vector<int> v(a, a + LOCAL_LENGTH);
    initializeLinkList<ListNode>(v, &head);
    printLinkList<ListNode>(head);
    head = sln.reverseList_recursive(head);
    printLinkList<ListNode>(head);
    destroyLinkList<ListNode>(head);
    return 0;
}
