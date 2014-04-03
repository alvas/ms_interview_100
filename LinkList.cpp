#include <iostream>
#include "LinkList.h"
#include "RandomData.h"

using namespace std;

LinkList::LinkList(int k)
{
    key = k;
    next = NULL;
}

void initializeLinkList(const vector<int> &S, LinkList **head)
{
    bool nullHead = true;
    LinkList *tmp = NULL;

    for (vector<int>::const_iterator itr = S.begin(); itr != S.end(); ++itr)
    {
        LinkList *p = new LinkList(*itr);

        if (nullHead)
        {
            *head = p;
            nullHead = false;
        }
        else
        {
            tmp->next = p;
        }
        
        tmp = p;
    }
}

void printLinkList(const LinkList *head)
{
    int column = 0;

    while (head != NULL)
    {
        cout << head->key << "\t";
        head = head->next;

        if (column++ % COLUMNS == COLUMNS - 1)
        {
            cout << endl;
        }
    }
}

void destroyLinkList(LinkList *head)
{
    while (head != NULL)
    {
        LinkList *tmp = head;
        head = head->next;
        delete tmp;
    }
}

void reverseLinkList(LinkList **head)
{
    LinkList *tmp = *head, *prevTmp = NULL, *nextTmp = NULL;

    while (tmp != NULL)
    {
        nextTmp = tmp->next;
        tmp->next = prevTmp;
        prevTmp = tmp;
        tmp = nextTmp;
    }

    *head = prevTmp;
}

#ifndef EXPORTED
int main()
{
    vector<int> S;
    initializeVector(S, LENGTH);
    printVector(S);
    LinkList *head = NULL;
    initializeLinkList(S, &head);
    reverseLinkList(&head);
    printLinkList(head);
    destroyLinkList(head);
    return 0;
}
#endif
