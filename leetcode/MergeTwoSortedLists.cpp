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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;

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
        else if (l2 != NULL)
        {
            p->next = l2;
        }

        p = head->next;
        delete head;
        return p;
    }

    ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2) {
        if (l1 == NULL)
        {
            return l2;
        }
        else if (l2 == NULL)
        {
            return l1;
        }

        ListNode *head = NULL, *p = NULL;

        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                if (head == NULL)
                {
                    head = l1;
                    p = l1;
                }
                else
                {
                    p->next = l1;
                    l1 = l1->next;
                    p = p->next;
                }
            }
            else
            {
                if (head == NULL)
                {
                    head = l2;
                    p = l2;
                }
                else
                {
                    p->next = l2;
                    l2 = l2->next;
                    p = p->next;
                }
            }
        }

        if (l1 != NULL)
        {
            p->next = l1;
        }
        else if (l2 != NULL)
        {
            p->next = l2;
        }
        
        return head;
    }

    ListNode *mergeTwoLists1(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL, *node = NULL;
        bool ascent = true, nondetermined = false;

        // Need to check what  order the list is sorted.
        if (l1 != NULL && l1->next != NULL)
        {
            if (l1->val > l1->next->val)
            {
                ascent = false;
            }
            else if (l1->val == l1->next->val)
            {
                nondetermined = true;
                ListNode *tmp = l1->next->next;

                while (tmp != NULL)
                {
                    if (l1->val > tmp->val)
                    {
                        ascent = false;
                        nondetermined = false;
                        break;
                    }
                    else if (l1->val == tmp->val)
                    {
                        tmp = tmp->next;
                    }
                    else
                    {
                        nondetermined = false;
                        break;
                    }
                }
            }
        }

        if (nondetermined && l2 != NULL && l2->next != NULL)
        {
            if (l2->val > l2->next->val)
            {
                ascent = false;
            }
            else if (l2->val == l2->next->val)
            {
                nondetermined = true;
                ListNode *tmp = l2->next->next;

                while (tmp != NULL)
                {
                    if (l2->val > tmp->val)
                    {
                        ascent = false;
                        break;
                    }
                    else if (l2->val == tmp->val)
                    {
                        tmp = tmp->next;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        // set the header of the list
        if (l1 != NULL && l2 != NULL)
        {
            if (ascent)
            {
                if (l1->val < l2->val)
                {
                    head = l1;
                    l1 = l1->next;
                }
                else
                {
                    head = l2;
                    l2 = l2->next;
                }
            }
            else
            {
                if (l1->val > l2->val)
                {
                    head = l1;
                    l1 = l1->next;
                }
                else
                {
                    head = l2;
                    l2 = l2->next;
                }
            }

            node = head;
        }

        while (l1 != NULL && l2 != NULL)
        {
            if (ascent)
            {
                if (l1->val < l2->val)
                {
                    node->next = l1;
                    node = node->next;
                    l1 = l1->next;
                }
                else
                {
                    node->next = l2;
                    node = node->next;
                    l2 = l2->next;
                }
            }
            else
            {
                if (l1->val > l2->val)
                {
                    node->next = l1;
                    node = node->next;
                    l1 = l1->next;
                }
                else
                {
                    node->next = l2;
                    node = node->next;
                    l2 = l2->next;
                }
            }
        }

        // append the rest of the list to the merged list.
        if (node != NULL)
        {
            if (l1 != NULL)
            {
                node->next = l1;
            }
            else
            {
                node->next = l2;
            }
        }
        else
        {
            if (l1 != NULL)
            {
                head = l1;
            }
            else
            {
                head = l2;
            }
        }

        return head;
    }
};

int main()
{
    Solution sln;
    ListNode *l1 = NULL, *l2 = NULL;
    vector<int> v1, v2;
    // 1. l1 empty; l2 empty; both l1 l2 empty;
    // 2. l1 1 element; l2 1 element;
    // 3. l1 multiple elments, l2 1 element; l1 1 element, l2 multiple elements;
    // 4. l1 l2 are the same;
    // 5. l1 multiple elements, l2 mutiple elements; swap l1 and l2;
    // 6. ascent or descent order; assume order of l1 and l2 are the compatible
    std::cout << "Please enter number of node of l1: ";
    int n1 = 0;
    cin >> n1;

    for (int i = 0; i < n1; ++i)
    {
        std::cout << "Please enter element of l1: ";
        int a = 0;
        cin >> a;
        v1.push_back(a);
    }

    std::cout << endl;
    std::cout << "Please enter number of node of l2: ";
    int n2 = 0;
    cin >> n2;

    for (int i = 0; i < n2; ++i)
    {
        std::cout << "Please enter element of l2: ";
        int a = 0;
        cin >> a;
        v2.push_back(a);
    }

    initializeLinkList<ListNode>(v1, &l1);
    initializeLinkList<ListNode>(v2, &l2);
    ListNode *head = sln.mergeTwoLists(l1, l2);
    printLinkList<ListNode>(head);
    destroyLinkList<ListNode>(head);
    return 0;
}

