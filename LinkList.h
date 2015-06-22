#include <cassert>
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
    void Print() { cout << this->val << "\t"; }
};

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}

    void Print()
    {
        cout << this->label;
        
        if (random != NULL)
        {
            cout << " >> " << random->label;
        }

        cout << "\t";
    }
};

template<typename T>
void initializeLinkList(const vector<int> &S, T **head)
{
    assert(head != NULL);

    if (head == NULL)
    {
        return;
    }

    *head = NULL;
    T *tmp = NULL;

    for (vector<int>::const_iterator itr = S.begin(); itr != S.end(); ++itr)
    {
        T *p = new T(*itr);

        if (*head == NULL)
        {
            *head = p;
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


        do
        {
            T *tmp = p;
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
        l->Print();
        l = l->next;
    }

    cout << endl;
}

template <typename T>
bool isCircleLinkList(T *l)
{
    if (l == NULL)
    {
        return false;
    }

    T *slow = l, *fast = l;

    do
    {
        slow = slow->next;
        fast = fast->next;

        if (fast != NULL)
        {
            fast = fast->next;
        }
    } while (slow != NULL && fast != NULL && slow != fast);

    cout << "Linked list has circle: " << (slow != NULL && fast != NULL) << endl;
    return slow != NULL && fast != NULL;
}

// Make the tail pointing to the nth node.
template <typename T>
void makeCircleLinkList(T *l, int n)
{
    if (l == NULL || isCircleLinkList(l))
    {
        return;
    }

    int len = 0;
    T *p = l, *tail = NULL;

    while (p != NULL)
    {
        len++;
        tail = p;
        p = p->next;
    }

    // Because l is not null, len could not be 0.
    n %= len;
    p = l;

    // In order to find the nth node, only need to move (n - 1) steps.
    while (--n > 0)
    {
        p = p->next;
    }

    tail->next = p;

    return;
}


template <typename T>
int findCircleLinkListIntersection(T *l)
{
    int pos = 0;

    if (l == NULL)
    {
        return pos;
    }
    
    T *slow = l, *fast = l;

    if (isCircleLinkList(l))
    {
        do
        {
            slow = slow->next;
            fast = fast->next;

            if (fast != NULL)
            {
                fast = fast->next;
            }
        } while (slow != NULL && fast != NULL && slow != fast);

        slow = l;
        pos++;

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
            pos++;
        }
    }

    cout << pos <<  " node is intersection point with value " << slow->val << endl;
    return pos;
}

template <typename T>
int getCircleLengthOfLinkList(T *l)
{
    if (l == NULL || !isCircleLinkList(l))
    {
        return 0;
    }

    T *p = l, *t = l;
    int pos = findCircleLinkListIntersection(l), len = 1;

    // move p to the intersection point
    while (--pos)
    {
        p = p->next;
    }

    t = p;
    cout << "The circle is : ";

    // go one round and get back to the intersection point, cound the length of the circle
    while (t->next != p)
    {
        cout << t->val << "\t";
        t = t->next;
        len++;
    }

    cout << t->val << "\t" << endl;
    cout << "The length of circle is " << len << endl;
    return len;
}

template <typename T>
void breakCircleLinkList(T *l)
{
    if (l == NULL)
    {
        return;
    }

    if (isCircleLinkList<ListNode>(l))
    {
        int pos = findCircleLinkListIntersection<ListNode>(l);
        int len = getCircleLengthOfLinkList<ListNode>(l);

        // Be careful about the step!!
        // Go to the intersection point at pos need (pos - 1) steps.
        // Then go to the tail from that point need (len - 1) steps.
        int step = pos - 1 + len - 1;
        T *p = l;

        while (step--)
        {
            p = p->next;
        }

        p->next = NULL;
    }

    return;
}

void createRandLink(RandomListNode *head, int nodeIdx, int randIdx);
