#include <vector>
#include <set>

using namespace std;

class LinkListNode
{
    public:
        LinkListNode(int);
        LinkListNode *GetHead();

        int val;
        LinkListNode *next;
};

class DoubleLinkListNode: public LinkListNode
{
    public:
        DoubleLinkListNode(int);

        DoubleLinkListNode *prev;
};

class LinkList
{
    public:
        LinkList() { head = NULL; };
        LinkList(const vector<int> &S);
        ~LinkList();
        LinkListNode *GetHead();
        LinkListNode *InsertNode(int value);

        LinkListNode *head;
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    int GetValue() { return val; }
    ListNode *GetNext() { return next; }
};

void destroyLinkList(LinkListNode *head);

template<typename T>
void initializeLinkList(const vector<int> &S, T **head)
{
    bool nullHead = true;
    T *tmp = NULL;

    for (vector<int>::const_iterator itr = S.begin(); itr != S.end(); ++itr)
    {
        T *p = new T(*itr);

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

// Passing the header of link list, this function would free all nodes
// on the link list. There is no need to loop through the link list
// to call this function.
template <typename T>
void destroyLinkList(T *p)
{
    if (p != NULL)
    {

        // 2014-04-12
        // This is a tmp variable to save the old header in order to stop
        // deleting circular link list.
        T *head = p;

#ifdef DEBUG
        cout << "The address of head is " << head << endl;
#endif

        do
        {
            T *tmp = p;
#ifdef DEBUG
            cout << "Deleting node " << tmp->val << endl;
            cout << "Next node " << p->val << "; ";
            cout << "The address of next node is " << p->next << endl;
#endif
            p = p->next;
            delete tmp;
        } while (p!= NULL && p!= head);
    }
}

template <typename  T>
void concatenateList(T *listA, int n, T *listB)
{
    if (listA == NULL || listB == NULL)
    {
        return;
    }

    T *node = listA;

    for (int i = 0; i < n && node->next != NULL; ++i)
    {
        node = node->next;
    }

    T *node2 = listB;

    while (node2->next != NULL)
    {
        node2 = node2->next;
    }

    node2->next = node;
}

template <typename T>
void disjointList(T *listA, T *listB)
{
    if (listA == NULL || listB == NULL || listA == listB)
    {
        return;
    }

    T *node = listA;
    set<T *> s;

    while (node->next != NULL && node->next != listB)
    {
        s.insert(node);
        node = node->next;
    }

    if (node->next == listB)
    {
        node->next = NULL;
        return;
    }

    s.insert(node);

    T *node2 = listB;

    while (node2->next != NULL)
    {
        if (s.find(node2->next) != s.end())
        {
            node2->next = NULL;
            break;
        }

        node2 = node2->next;
    }
}

template <typename T>
void printLinkList(T *l)
{
    cout << "Printing the link list:" << endl;

    while (l != NULL)
    {
        cout << l->GetValue() << endl;
        l = l->GetNext();
    }

    cout << endl;
}
