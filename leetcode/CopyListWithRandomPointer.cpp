#include <iostream>
#include <map>
#include <utility>
#include <vector>

#include "LinkList.h"
#include "NormalData.h"

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    // Need to improve.
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *copyHead = NULL;

        if (head == NULL)
        {
            return copyHead;
        }

        map<RandomListNode *, RandomListNode *> m;
        RandomListNode *node = head;

        while (node != NULL)
        {
            RandomListNode *copy = NULL;
            map<RandomListNode *, RandomListNode *>::iterator itr1 = m.find(node);

            if (itr1 == m.end())
            {
                copy = new RandomListNode(node->label);
                m.insert(make_pair(node, copy));
            }
            else
            {
                copy = itr1->second;
            }

            if (copyHead == NULL)
            {
                copyHead = copy;
            }

            RandomListNode *next = node->next, *copyNext = NULL;
            map<RandomListNode *, RandomListNode *>::iterator itr2 = m.find(next);

            // Check the NULL pointer.
            if (next != NULL)
            {
                if (itr2 == m.end())
                {
                    copyNext = new RandomListNode(next->label);
                    m.insert(make_pair(next, copyNext));
                    // Don't forget to set the value
                    copy->next = copyNext;
                }
                else
                {
                    copyNext = itr2->second;
                    copy->next = copyNext;
                }
            }

            RandomListNode *random = node->random, *copyRandom = NULL;
            map<RandomListNode *, RandomListNode *>::iterator itr3 = m.find(random);

            // Check the NULL pointer.
            if (random != NULL)
            {
                if (itr3 == m.end())
                {
                    copyRandom = new RandomListNode(random->label);
                    m.insert(make_pair(random, copyRandom));
                    // Don't forget to set the value
                    copy->random = copyRandom;
                }
                else
                {
                    copyRandom = itr3->second;
                    copy->random = copyRandom;
                }
            }

            node = node->next;
        }

        return copyHead;
    }
};

int main()
{
    Solution sln;
    vector<int> v = {1, 2, 3, 4, 5};
    RandomListNode *head = NULL;
    initializeLinkList<RandomListNode>(v, &head);
    createRandLink(head, 2, 1);
    createRandLink(head, 3, 2);
    printLinkList<RandomListNode>(head);
    RandomListNode *copy = sln.copyRandomList(head);
    printLinkList<RandomListNode>(copy);
    destroyLinkList<RandomListNode>(head);
    destroyLinkList<RandomListNode>(copy);
    return 0;
}
