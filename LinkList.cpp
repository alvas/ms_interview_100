#include <iostream>
#include "LinkList.h"
#include "NormalData.h"
#include "RandomData.h"

LinkListNode::LinkListNode(int k)
{
    key = k;
    next = NULL;
}

void initializeLinkList(const vector<int> &S, LinkListNode **head)
{
    bool nullHead = true;
    LinkListNode *tmp = NULL;

    for (vector<int>::const_iterator itr = S.begin(); itr != S.end(); ++itr)
    {
        LinkListNode *p = new LinkListNode(*itr);

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
    initializeLinkList(S, &head);
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

// Passing the header of link list, this function would free all nodes
// on the link list. There is no need to loop through the link list
// to call this function.
void destroyLinkList(LinkListNode *p)
{
    if (p != NULL)
    {

        // 2014-04-12
        // This is a tmp variable to save the old header in order to stop
        // deleting circular link list.
        LinkListNode *head = p;

#ifdef DEBUG
        cout << "The address of head is " << head << endl;
#endif

        do
        {
            LinkListNode *tmp = p;
#ifdef DEBUG
            cout << "Deleting node " << tmp->key << endl;
            cout << "Next node " << p->key << "; ";
            cout << "The address of next node is " << p->next << endl;
#endif
            p = p->next;
            delete tmp;
        } while (p!= NULL && p!= head);
    }
}

LinkList::~LinkList()
{
    destroyLinkList(head);
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
        cout << head->key << "\t";
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
