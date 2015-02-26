#include <cstdlib>
#include <iostream>

#include "../LinkList.h"

using namespace std;

const int lengthA = 5;
const int lengthB = 3;

class Solution {
public:
    // If two link list intersects, there are some common nodes on both lists.
    // Move forward from the head of longer list until two lists have the same number of nodes.
    // Start from there, compare whether the nodes are the same on both list.
    // If not, move forward on both list. If yes, then it is the intersection node.
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }

        int lengthA = 0, lengthB = 0;
        ListNode *a = headA, *b = headB;

        while (a != NULL)
        {
            lengthA++;
            a = a->next;
        }

        while (b != NULL)
        {
            lengthB++;
            b = b->next;
        }

        ListNode *longList = NULL, *shortList = NULL;
        int diff = abs(lengthA - lengthB);

        longList = (lengthA > lengthB) ? headA : headB;
        shortList = (lengthA > lengthB) ? headB : headA;

        for (int i = 0; i < diff; ++i)
        {
            longList = longList->next;
        }

        while (longList != NULL && shortList != NULL)
        {
            if (longList == shortList)
            {
                return longList;
            }

            longList = longList->next;
            shortList = shortList->next;
        }

        return NULL;
    }

    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        ListNode *node = NULL;

        if (headA == NULL || headB == NULL)
        {
            return node;
        }

        ListNode *a = headA;
        set<ListNode *> s;

        // insert all nodes on list A into set
        while (a != NULL)
        {
            s.insert(a);
            a = a->next;
        }

        ListNode *b = headB;

        // check whether node from b is in the set.
        // If yes, then it is the first intersection node.
        // Otherwise, move forward. If list B doesn't have
        // node appearing in the set, then there is no intersection.
        while (b != NULL)
        {
            if (s.find(b) != s.end())
            {
                return b;
            }

            b = b->next;
        }

        return node;
    }
};

int main()
{
    Solution sln;
    ListNode *headA = NULL, *headB = NULL;
    int A[lengthA] = {1, 2, 3, 4, 5}, B[lengthB] = {6, 7, 8};
    vector<int> va(A, A + lengthA), vb(B, B + lengthB);
    initializeLinkList<ListNode>(va, &headA);
    initializeLinkList<ListNode>(vb, &headB);
    concatenateList<ListNode>(headA, 3, headB);
    ListNode *node = sln.getIntersectionNode(headA, headB);
    //ListNode *node = sln.getIntersectionNode1(headA, headB);

    if (node != NULL)
    {
        cout << "The join node is: " << node->val << endl;
    }

    disjointList<ListNode>(headA, headB);
    destroyLinkList<ListNode>(headA);
    destroyLinkList<ListNode>(headB);
    return 0;
}

