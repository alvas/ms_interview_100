#include <iostream>

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
        if (head == NULL)
        {
            return head;
        }

        ListNode *node = head, prev = NULL;

        while (node != NULL)
        {
            if (prev == NULL)
            {
                prev = node;
                node = node->next;
            }

            if (prev->val == node->val && node->next != NULL)
            {
                continue;
            }
        }
    }
};

int main()
{
    Solution sln;
    ListNode *head = NULL;
    head = sln.deleteDuplicates(head);
    return 0;
}

