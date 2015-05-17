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
    // Need to improve performance.
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        int len = getLength(head);
        vector<ListNode *> v;
        ListNode *cur = head;

        for (int i = 0; i < len; ++i)
        {
            v.push_back(cur);
            cur = cur->next;
        }

        int halfLen = (len - 1) / 2;
        cur = head;

        for (int i = 0; i < halfLen; ++i)
        {
            cur->next = v[len - 1 - i];
            cur = cur->next;
            cur->next = v[i + 1];
            cur = cur->next;
        }

        v[len / 2]->next = NULL;
        return;
    }

    void reorderList_naive(ListNode* head) {
        if (head == NULL)
        {
            return;
        }

        int len = getLength(head), halfLen = (len + 1) / 2;
        makeCircle(head);

        for (int i = 1, step = 1; i < halfLen; ++i, step = step + 2)
        {
            moveAhead(head, step);
        }

        breakCircle(head);
        return;
    }

    int getLength(ListNode *head)
    {
        int count = 0;
        ListNode *p = head;

        while (p != NULL)
        {
            count++;
            p = p->next;
        }

        return count;
    }

    ListNode *makeCircle(ListNode *head)
    {
        ListNode *cur = head, *tail = NULL;

        while (cur != NULL)
        {
            tail = cur;
            cur = cur->next;
        }

        if (tail != NULL)
        {
            tail->next = head;
        }

        return tail;
    }

    ListNode *findTail(ListNode *head, ListNode **preTail = NULL)
    {
        ListNode *cur = head, *tail = NULL;

        while (cur != NULL)
        {
            if (preTail != NULL)
            {
                *preTail = tail;
            }

            tail = cur;
            cur = cur->next;

            if (cur == head)
            {
                break;
            }
        }

        return tail;
    }

    void breakCircle(ListNode *head)
    {
        ListNode *tail = findTail(head);

        if (tail != NULL)
        {
            tail->next = NULL;
        }
    }

    ListNode *findPrev(ListNode *head, ListNode *node)
    {
        ListNode *p = NULL, *cur = head;

        while (cur != NULL && cur != node)
        {
            p = cur;
            cur = cur->next;
        }

        return p;
    }

    void moveAhead(ListNode *head, int step)
    {
        ListNode *prev = NULL;
        ListNode *tail = findTail(head, &prev);
        // Be careful about moving the first node
        ListNode *cur = head;

        while (--step > 0 && cur != NULL)
        {
            cur = cur->next;
        }

        if (prev != NULL && tail != NULL && cur != NULL)
        {
            prev->next = head;
            tail->next = cur->next;
            cur->next = tail;
        }
    }
};

int main()
{
    Solution sln;
    const int LOCAL_LENGTH = 6;
    //int a[LOCAL_LENGTH] = {1};
    //int a[LOCAL_LENGTH] = {1, 2};
    //int a[LOCAL_LENGTH] = {1, 2, 3};
    //int a[LOCAL_LENGTH] = {1, 2, 3, 4};
    //int a[LOCAL_LENGTH] = {1, 2, 3, 4, 5};
    int a[LOCAL_LENGTH] = {1, 2, 3, 4, 5, 6};
    vector<int> v(a, a + LOCAL_LENGTH);
    ListNode *head = NULL, *head2 = NULL;
    initializeLinkList<ListNode>(v, &head);
    initializeLinkList<ListNode>(v, &head2);
    sln.reorderList(head);
    sln.reorderList_naive(head2);
    printLinkList<ListNode>(head);
    printLinkList<ListNode>(head2);
    destroyLinkList<ListNode>(head);
    destroyLinkList<ListNode>(head2);
    return 0;
}
