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
    // Need to improve.
    ListNode* partition(ListNode* head, int x) {
        if (head != NULL)
        {
            ListNode *node = head;
            vector<int> v;

            while (node != NULL)
            {
                v.push_back(node->val);
                node = node->next;
            }

            int size = v.size();
            vector<int> v2;

            for (int i = 0; i < size; ++i)
            {
                if (v[i] < x)
                {
                    v2.push_back(v[i]);
                }
            }
            
            for (int i = 0; i < size; ++i)
            {
                if (v[i] >= x)
                {
                    v2.push_back(v[i]);
                }
            }

            node = head;

            for (int i = 0; i < size; ++i)
            {
                node->val = v2[i];
                node = node->next;
            }
        }

        return head;
    }
};

int main()
{
    Solution sln;
    int x = 0;
    cout << "Please enter x: ";
    cin >> x;
    int a[] = {1, 4, 3, 2, 5, 2};
    vector<int> v(a, a + SIZE(a));
    ListNode *head = NULL;
    initializeLinkList<ListNode>(v, &head);
    printLinkList<ListNode>(head);
    head = sln.partition(head, x);
    printLinkList<ListNode>(head);
    destroyLinkList<ListNode>(head);
    return 0;
}
