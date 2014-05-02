#include <vector>

using namespace std;

class LinkListNode
{
    public:
        LinkListNode(int);
        LinkListNode *GetHead();

        int key;
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

void destroyLinkList(LinkListNode *head);
