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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
        {
            return head;
        }

        // prev initialization is important.
        ListNode *p = head, *prev = head;

        while (p != NULL)
        {
            if (p->val != val)
            {
                prev = p;
                p = p->next;
            }
            else
            {
                ListNode *tmp = p->next;

                // setting the prev and prev->next is important.
                if (prev == p)
                {
                    // if the head of the linked list is delete, set prev and head correctly.
                    prev = tmp;
                    head = prev;
                }
                else
                {
                    // connect the linked list correctly.
                    prev->next = tmp;
                }

                delete p;
                p = tmp;
            }
        }

        return head;
    }
};

int main()
{
    Solution sln;
    ListNode *root = NULL;
    vector<int> v;
    int n = 0;
    std::cout << "Please enter the number of nodes in linked list: ";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int t = 0;
        std::cout << "Please enter value: ";
        cin >> t;
        v.push_back(t);
    }

    int val = 0;
    std::cout << "Please enter the value you want to remove: ";
    cin >> val;

    initializeLinkList<ListNode>(v, &root);
    printLinkList<ListNode>(root);
    root = sln.removeElements(root, val);
    printLinkList<ListNode>(root);
    destroyLinkList<ListNode>(root);
    return 0;
}
