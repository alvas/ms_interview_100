#include <iostream>

#include "LinkList.h"
#include "NormalData.h"

using namespace std;

const int LOCAL_LENGTH = 10;

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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
        {
            return NULL;
        }

        ListNode *slow = head, *fast = head;

        do
        {
            slow = slow->next;
            fast = fast->next;

            if (fast != NULL)
            {
                fast = fast->next;
            }
        } while (slow != fast && slow != NULL && fast != NULL);

        if (slow == NULL || fast == NULL)
        {
            return NULL;
        }

        slow = head;

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

int main()
{
    Solution sln;
    vector<int> S;
    initializeIndexVector(S, LOCAL_LENGTH);

    ListNode *list = NULL;
    initializeLinkList<ListNode>(S, &list);
    printLinkList<ListNode>(list);

    int n = 5;
    makeCircleLinkList<ListNode>(list, n);

    ListNode *p = sln.detectCycle(list);

    if (p == NULL)
    {
        cout << "There is no circle!" << endl;
    }
    else
    {
        cout << "The circle begins from: " << p->val << endl;
    }

    breakCircleLinkList<ListNode>(list);

    destroyLinkList<ListNode>(list);
    return 0;
}
