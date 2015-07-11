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
            return false;
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

        while (t != NULL)
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

        ListNode *node = root;

        return node;
    }
};

int main()
{
    Solution sln;
    //int a[] = {1, 2, 3};
    //vector<int> v(a, a + SIZE(a));
    vector<int> v;
    initializeRandomVector(v, LENGTH);
    ListNode *head = NULL;
    initializeLinkList<ListNode>(v, &head);
    printLinkList<ListNode>(head);
    cout << sln.isPalindrome(head) << endl;
    return 0;
}
