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

    LinkListNode *p = list.GetCurrent();

    if (head != NULL)
    {
        do
        {
            cout << "Current node " << list.current->key << endl;
            list.current = list.current->next;
        } while (list.current != head);
    }
}

#ifndef EXPORTED
int main()
{
    vector<int> v;
    initializeIndexVector(v, SIZE);
    CircularLinkList list(v);
    printCircularLinkList(list);
    cout << "The current node is: " << list.GetCurrent()->key << endl;
    return 0;
}
#endif
