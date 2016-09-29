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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        p = head; 
        len= 0;

        while (head) {
            len++;
            head = head->next;
        }

        std::srand((unsigned)std::time(0));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int v = p ? p->val : 0, i = 2;
        ListNode *t = p ? p->next : nullptr;

        while (t) {
            int r = rand() % i;

            if (!r) {
                v = t->val;
            }

            t = t->next;
            i++;
        }

        return v;
    }

    int getRandom1() {
        int r = rand() % len;
        ListNode *t = p;

        while (r--) {
            if (!t) {
                t = p;
            }

            t = t->next;
        }

        return t == nullptr ? 0 : t->val;
    }

    ListNode *p;
    int len;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

int main() {
    vector<int> v = {1, 2, 3};
    ListNode *head = nullptr;
    initializeLinkList<ListNode>(v, &head);
    Solution sln(head);
    cout << sln.getRandom() << endl;
    destroyLinkList<ListNode>(head);
    return 0;
}
