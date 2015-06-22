#include <algorithm>
#include <iostream>
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
    // IMPORTANT!! Remember to declar myfunction as statick.
    static bool myfunction(pair<ListNode *, int> a, pair<ListNode *, int> b)
    {
        return a.first->val > b.first->val;
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
    int k = rand() % 15;
    vector<ListNode *> lists;

    for (int i = 0; i < k; ++i)
    {
        vector<int> v;
        initializeMRandomVector(v, rand() % 18);
        sort(v.begin(), v.end());
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
