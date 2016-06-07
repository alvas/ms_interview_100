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
    ListNode* partition(ListNode* head, int x) {
        ListNode *leftDummy = new ListNode(0);
        ListNode *rightDummy = new ListNode(0);
        ListNode *leftTail = leftDummy;
        ListNode *rightTail = rightDummy;

        while (head != nullptr)
        {
            if (head->val < x)
            {
                leftTail->next = head;
                leftTail = head;
            }
            else
            {
                rightTail->next = head;
                rightTail = head;
            }

            head = head->next;
        }

        leftTail->next = rightDummy->next;
        rightTail->next = NULL;

        head = leftDummy->next;
        delete leftDummy;
        delete rightDummy;
        return head;
    }

    // Need to improve.
    ListNode* partition1(ListNode* head, int x) {
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
    std::cout << "Please enter x: ";
    cin >> x;
    vector<int> v = {1, 4, 3, 2, 5, 2};
    ListNode *head = NULL;
    initializeLinkList<ListNode>(v, &head);
    printLinkList<ListNode>(head);
    head = sln.partition(head, x);
    printLinkList<ListNode>(head);
    destroyLinkList<ListNode>(head);
    return 0;
}
