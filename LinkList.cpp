#include <iostream>
#include "LinkList.h"
#include "RandomData.h"

LinkListNode::LinkListNode(int k)
{
    val = k;
    next = NULL;
}


void initializeLinkList(LinkList &list, const vector<int> &S)
{
    bool initialize = true;

    for (vector<int>::const_iterator itr = S.begin(); itr != S.end(); ++itr)
    {
        if (initialize)
        {
            initialize = false;
            list.head = list.InsertNode(*itr);
        }
        else
        {
            list.InsertNode(*itr);
        }
    }
}

LinkList::LinkList(const vector<int> &S)
{
    initializeLinkList<LinkListNode>(S, &head);
}

LinkListNode *LinkList::InsertNode(int value)
{
    if (head == NULL)
    {
        LinkListNode *p = new LinkListNode(value);
        return p;
    }
    else
    {
        LinkListNode *p = head;

        while (p->next != NULL)
        {
            p = p->next;
        }

        p->next = new LinkListNode(value);
        return p->next;
    }
}


LinkList::~LinkList()
{
    destroyLinkList<LinkListNode>(head);
    head = NULL;
}

LinkListNode *LinkList::GetHead()
{
    return head;
}

void printLinkListNode(const LinkListNode *head)
{
    int column = 0;

    while (head != NULL)
    {
        cout << head->val << "\t";
        head = head->next;

        if (column++ % COLUMNS == COLUMNS - 1)
        {
            cout << endl;
        }
    }
}


void reverseLinkList(LinkListNode **head)
{
    LinkListNode *tmp = *head, *prevTmp = NULL, *nextTmp = NULL;

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
    initializeRandomVector(S, LENGTH);
    /*
    printVector(S);
    LinkListNode *head = NULL;
    initializeLinkList(S, &head);
    reverseLinkList(&head);
    printLinkListNode(head);
    destroyLinkList(head);
    */

    LinkList list;
    initializeLinkList(list, S);
    printLinkListNode(list.head);
    return 0;
}
#endif
