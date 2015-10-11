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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k <= 0)
        {
            return head;
        }

        int sz = 0;
        ListNode *node = head, *tail = NULL;

        while (node != NULL)
        {
            tail = node;
            node = node->next;
            sz++;
        }

        k %= sz;
        int step = ((2 * sz) - k - 1 ) % sz;
        node = head;

        for (int i = 0; i < step; ++i)
        {
            node = node->next;
        }

        tail->next = head;
        head = node->next;
        node->next = NULL;
        return head;
    }
};

int main()
{
    Solution sln;
    vector<int> a = {1, 2, 3, 4, 5};
    //vector<int> a = {1};
    //vector<int> a = {1, 2};
    //vector<int> a = {1, 2, 3};
    vector<int> v(a, a + SIZE(a));
    int k = 0;
    cout << "Please enter k[1, " << SIZE(a) << "]: ";
    cin >> k;
    ListNode *head = NULL;
    initializeLinkList<ListNode>(v, &head);
    printLinkList<ListNode>(head);
    head = sln.rotateRight(head, k);
    printLinkList<ListNode>(head);
    destroyLinkList<ListNode>(head);
    return 0;
}
