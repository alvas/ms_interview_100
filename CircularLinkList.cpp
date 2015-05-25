#include <iostream>
#include "CircularLinkList.h"
#include "NormalData.h"

const int SIZE = 7;

CircularLinkList::CircularLinkList(const vector<int> S)
{
    bool initialize = true;
    LinkListNode *tmp = NULL;

    for (vector<int>::const_iterator itr = S.begin(); itr != S.end(); ++itr)
    {
        LinkListNode *p = new LinkListNode(*itr);

        if (initialize)
        {
            current = p;
            initialize= false;
        }
        else
        {
            tmp->next = p;
        }
        
        tmp = p;
    }

    // Set the last node's next to the head node.
    tmp->next = current;
}

CircularLinkList::~CircularLinkList()
{
    destroyLinkList(current);
    current = NULL;
}

LinkListNode *CircularLinkList::GetCurrent()
{
    return current;
}

void printCircularLinkList(CircularLinkList &list)
{
    LinkListNode *head = list.GetCurrent();

    if (head != NULL)
    {
        do
        {
            cout << "Current node " << list.current->val << endl;
            list.current = list.current->next;
        } while (list.current != head);
        // When we loop back to the head of the circular link list, we stop.
    }
}

#ifndef EXPORTED
int main()
{
    vector<int> v;
    initializeIndexVector(v, SIZE);
    CircularLinkList list(v);
    printCircularLinkList(list);
    cout << "The current node is: " << list.GetCurrent()->val << endl;
    return 0;
}
#endif
