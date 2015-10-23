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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *pioneer = head;

        while (pioneer != NULL && --n > 0)
        {
            pioneer = pioneer->next;
        }

        if (pioneer == NULL)
        {
            return head;
        }

        pioneer = pioneer->next;
        ListNode *node = head, *prev = NULL;

        while (pioneer != NULL)
        {
            pioneer = pioneer->next;
            prev = node;
            node = node->next;
        }

        if (node != NULL)
        {
            if (prev != NULL)
            {
                prev->next = node->next;
            }
            else
            {
                // remove the first node on list
                head = node->next;
            }
        }

        delete node;

        return head;
    }

    // This interface pass in ListNode *head, we can change the value of head itself.
    // How to remove the only node in case the case {1}, 1??
    // Answer: the return value is the head node. The removed node needs to be delete
    // inside this function.
    // Need to improve!!
    ListNode *removeNthFromEnd1(ListNode *head, int n) {
        vector<ListNode *> v;
        ListNode *node = head;

        while (node != NULL)
        {
            v.push_back(node);
            node = node->next;
        }

        int size = v.size();
        node = NULL;

        // Watch out for corner case
        // 1. list is empty
        // 2. list has 1 node and delete this node
        // 3. list has 2 nodes, remove the first and second
        // 4. list has more than 2 nodes, remove the first and last node
        // 5. list has more than 2 nodes, remove middle node
        if (size > 0)
        {
            if (size > n)
            {
                if (n != 1)
                {
                    node = v[size - n];
                    v[size - n - 1]->next = v[size - n + 1];
                }
                else
                {
                    // remove the last node
                    node = v[size - n];
                    v[size - n - 1]->next = NULL;
                }
            }
            // remove the first node; or remove the only node;
            else if (size == n)
            {
                node = v[0];
                // Be careful!! don't use head = v[1] here, because the list can
                // have only 1 node.
                head = v[0]->next;
            }
        }

        delete node;
        node = NULL;

        return head;
    }
};

int main()
{
    Solution sln;


    //int A[lengthA] = {1};
    //const int lengthA = 1;
    //vector<int> va(A, A + lengthA);
    vector<int> va;
    
    int size = 0;
    std::cout << "Please enter the size of the list: ";
    cin >> size;

    for (int i = 0; i < size; ++i)
    {
        int a = 0;
        std::cout << "please enter value of node on the list: ";
        cin >> a;
        va.push_back(a);
    }

    ListNode *head = NULL;
    initializeLinkList<ListNode>(va, &head);

    int n = 0;
    std::cout << "Pleae enter the nth node to remove: ";
    cin >> n;

    head = sln.removeNthFromEnd(head, n);

    destroyLinkList<ListNode>(head);
    head = NULL;

    return 0;
}
