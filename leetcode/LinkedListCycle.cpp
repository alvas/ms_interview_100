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
    bool hasCycle(ListNode *head) {
        if (head == NULL)
        {
            return false;
        }

        // Be careful about the initial value of fast.
        // If fast = head, then the first time slow == true
        // would be true. This is incorrect.
        ListNode *slow = head, *fast  = head->next;

        while (slow != NULL && fast != NULL)
        {
            if (slow == fast)
            {
                return true;
            }

            slow = slow->next;
            fast = fast->next;

            if (fast != NULL)
            {
                fast = fast->next;
            }
        }

        return false;
    }
};

int main()
{
    Solution sln;
    ListNode *head = NULL;
    int num = 0;
    cout << "Please enter node number: ";
    cin >> num;
    vector<int> v;

    for (int i = 0; i < num; ++i)
    {
        int t = 0;
        cout << "Please enter val: ";
        cin >> t;
        v.push_back(t);
    }

    initializeLinkList<ListNode>(v, &head);
    cout << sln.hasCycle(head) << endl;
    destroyLinkList<ListNode>(head);
    return 0;
}
