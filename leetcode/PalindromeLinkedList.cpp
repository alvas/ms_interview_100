#include <iostream>
#include <vector>

#include "LinkList.h"
#include "RandomData.h"

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
    bool isPalindrome(ListNode* head) {
        if (head == NULL)
        {
            return true;
        }

        int len = 0;
        ListNode *p = head;

        while (p != NULL)
        {
            len++;
            p = p->next;
        }

        int half = (len + 1) / 2;
        ListNode *t = head;

        for (int i = 0; i < half; ++i)
        {
            t = t->next;
        }

        t = reverseList(t);
        ListNode *s = head; 

        while (t != NULL && s != NULL)
        {
            if (s->val != t->val)
            {
                return false;
            }

            s = s->next;
            t = t->next;
        }

        return true;
    }

    ListNode *reverseList(ListNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }

        ListNode *prev = NULL, *node = root, *next = root->next;

        while (next != NULL)
        {
            node->next = prev;
            prev = node;
            node = next;
            next = next->next;
        }

        node->next = prev;

        return node;
    }
};

int main()
{
    Solution sln;
    //vector<int> v = {1};
    //vector<int> v = {1, 1};
    //vector<int> v = {1, 2, 3, 2, 1};
    //vector<int> v = {1, 2, 1, 3, 1};
    vector<int> v = {1, 2, 1, 1, 1};
    //vector<int> v = {1, 2, 3, 3, 2, 1};
    //vector<int> v;
    //initializeRandomVector(v, LENGTH);
    ListNode *head = NULL;
    initializeLinkList<ListNode>(v, &head);
    printLinkList<ListNode>(head);
    std::cout << sln.isPalindrome(head) << endl;
    return 0;
}
