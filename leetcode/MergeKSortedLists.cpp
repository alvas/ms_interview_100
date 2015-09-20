#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
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
    // IMPORTANT!! Remember to declare myfunction as static.
    static bool myfunction(pair<ListNode *, int> a, pair<ListNode *, int> b)
    {
        return a.first->val > b.first->val;
    }

    class mycomparision
    {
    public:
        bool operator() (ListNode * a, ListNode * b)
        {
            return a->val >= b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if (n == 0)
        {
            return NULL;
        }

        int e = n - 1;

        while (e > 0)
        {
            int b = 0;

            while (b < e)
            {
                lists[b] = merge2Lists(lists[b], lists[e]);
                b++;
                e--;
            }
        }

        return lists[0];
    }

    ListNode *merge2Lists(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;

        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }

            p = p->next;
        }

        if (l1 != NULL)
        {
            p->next = l1;
        }

        if (l2 != NULL)
        {
            p->next = l2;
        }

        p = dummy->next;
        delete dummy;
        return p;
    }

    ListNode* mergeKLists1(vector<ListNode*>& lists) {
        int n = lists.size();

        if (n == 0)
        {
            return NULL;
        }

        // This is wrong.
        //priority_queue<mycomparision, vector<ListNode *> > q;
        // This is correct.
        // default priority_queue is max heap, so mycomparision should define >= for increasing order.
        priority_queue<ListNode *, vector<ListNode *>, mycomparision> q;

        for (auto &l : lists)
        {
            if (l != NULL)
            {
                q.push(l);
            }
        }

        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;

        while (!q.empty())
        {
            ListNode *node = q.top();
            q.pop();
            p->next = node;
            p = p->next;

            if (node->next != NULL)
            {
                q.push(node->next);
            }
        }

        p = dummy->next;
        delete dummy;
        return p;
    }

    ListNode* mergeKLists_heap(vector<ListNode*>& lists) {
        ListNode *head = NULL;
        int sz = lists.size();

        if (sz == 0)
        {
            return head;
        }

        vector<pair<ListNode *, int> > v;

        for (int i = 0; i < sz; ++i)
        {
            if (lists[i] != NULL)
            {
                v.push_back(make_pair(lists[i], i));
                lists[i] = lists[i]->next;
            }
        }

        ListNode *tail = NULL;

        while (v.size())
        {
            make_heap(v.begin(), v.end(), myfunction);

            int a = v[0].second;

            if (head == NULL)
            {
                head = v[0].first;
                tail = head;
            }
            else
            {
                tail->next = v[0].first;
                tail = tail->next;
            }

            if (lists[a] != NULL)
            {
                pair<ListNode *, int> p = make_pair(lists[a], a);
                v[0] = p;
                lists[a] = lists[a]->next;
            }
            else
            {
                int szV = v.size();
                v[0] = v[szV - 1];
                v.resize(szV - 1);
            }
        }

        return head;
    }

    ListNode* mergeKLists_improved(vector<ListNode*>& lists) {
        ListNode *head = NULL;
        int sz = lists.size();

        if (sz == 0)
        {
            return head;
        }

        vector<int> v;
        ListNode *tail = NULL, *node = NULL;

        for (int i = 0; i < sz; ++i)
        {
            node = lists[i];

            if (node == NULL)
            {
                continue;
            }

            if (head == NULL)
            {
                head = node;
            }
            else
            {
                tail->next = lists[i];
            }

            while (node != NULL)
            {
                v.push_back(node->val);
                tail = node;
                node = node->next;
            }
        }

        sort(v.begin(), v.end());
        int szV = v.size();
        node = head;

        for (int i = 0; i < szV; ++i)
        {
            node->val = v[i];
            node = node->next;
        }

        return head;
    }

    ListNode* mergeKLists_slow(vector<ListNode*>& lists) {
        ListNode *head = NULL;
        int sz = lists.size();

        if (sz == 0)
        {
            return head;
        }

        bool leftover = true;
        ListNode *tail = NULL;

        while (leftover)
        {
            leftover = false;
            // Be careful. Use INT_MAX, not INT_MIN here. Otherwise, minV would not be set.
            int minIdx = 0, minV = INT_MAX;

            for (int i = 0; i < sz; ++i)
            {
                if (lists[i] != NULL)
                {
                    leftover = true;

                    if (lists[i]->val < minV)
                    {
                        minV = lists[i]->val;
                        minIdx = i;
                    }
                }
            }

            if (leftover)
            {
                if (head == NULL)
                {
                    head = lists[minIdx];
                    tail = head;
                    lists[minIdx] = lists[minIdx]->next;
                }
                else
                {
                    tail->next = lists[minIdx];
                    tail = tail->next;
                    lists[minIdx] = lists[minIdx]->next;
                }
            }
        }

        return head;
    }
};

int main()
{
    Solution sln;
    ListNode *head = NULL;
    srand(unsigned(time(0)));
    vector<ListNode *> lists;
    //int a[][5] = {{3, 7, 9, 12, 88}, {2, 6, 8, 10, 14}};
    int k = rand() % 8;
    //int k = SIZE(a);

    for (int i = 0; i < k; ++i)
    {
        vector<int> v;
        initializeMRandomVector(v, rand() % 18);
        sort(v.begin(), v.end());
        //vector<int> v(a[i], a[i] + SIZE(a[i]));
        initializeLinkList<ListNode>(v, &head);
        lists.push_back(head);
        head = NULL;
    }

    for (int i = 0; i < k; ++i)
    {
        ListNode *node = lists[i];
        printLinkList<ListNode>(node);

    }

    head = sln.mergeKLists(lists);
    printLinkList<ListNode>(head);
    destroyLinkList<ListNode>(head);
    return 0;
}
