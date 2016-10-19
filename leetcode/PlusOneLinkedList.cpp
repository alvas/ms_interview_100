#include <iostream>
#include <vector>

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
    ListNode* plusOne(ListNode* head) {
        if (!head) {
            return head;
        }

        ListNode* newListPtr = new ListNode(head->val);
        ListNode* oldListPtr = head->next;

        // be careful about the list population direction and list construction sequence
        while (oldListPtr) {
            ListNode* node = new ListNode(oldListPtr->val);
            node->next = newListPtr;
            newListPtr = node;
            node = oldListPtr;
            oldListPtr = oldListPtr->next;
            delete node;
        }

        int a = newListPtr->val + 1;
        int carry = a / 10;
        head = new ListNode(a % 10);
        // Don't miss move to next.
        newListPtr = newListPtr->next;

        // be careful about the list population direction and list construction sequence
        while (newListPtr) {
            a = newListPtr->val + carry;
            carry = a / 10;
            ListNode* node = new ListNode(a % 10);
            node->next = head;
            head = node;
            node = newListPtr;
            newListPtr = newListPtr->next;
            delete node;
        }

        if (carry) {
            ListNode* node = new ListNode(carry);
            node->next = head;
            head = node;
        }

        return head;
    }

    // BAD implementation. Overflow with large number.
    ListNode* plusOne1(ListNode* head) {
        if (!head) {
            return head;
        }

        ListNode* p = head;
        // still overflow with large number
        long long a = 0;

        while (p) {
            a = a * 10 + p->val;
            p = p->next;
        }

        a++;
        // still overflow with large number
        long long b = 1;

        while (a / b >= 10) {
            b *= 10;
        }

        p = head;
        ListNode* tail = p;

        while (b) {
            if (p != nullptr) {
                tail = p;
                p->val = a / b;
                p = p->next;
            }
            else {
                tail->next = new ListNode(a/b); 
            }

            a %= b;
            b /= 10;
        }

        return head;
    }
};

int main() {
    Solution sln;
    vector<int> v = {1, 2, 3};
    //vector<int> v = {6,1,4,5,3,9,0,1,9,5,1,8,6,7,0,5,5,4,3};
    //vector<int> v = {7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6};
    //vector<int> v = {9};
    //vector<int> v = {8, 9, 9, 9};
    ListNode *head = NULL;
    initializeLinkList(v, &head);
    printLinkList<ListNode>(head);
    head = sln.plusOne(head);
    printLinkList<ListNode>(head);
    destroyLinkList<ListNode>(head);
    return 0;
}
