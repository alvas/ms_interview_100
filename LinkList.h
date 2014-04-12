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

class LinkList
{
    public:
        LinkList() { head = NULL; };
        LinkList(const vector<int> &S);
        ~LinkList();
        LinkListNode *GetHead();

    private:
        LinkListNode *head;
};

class DoubleLinkListNode: public LinkListNode
{
    public:
        DoubleLinkListNode(int);

        DoubleLinkListNode *prev;
};

void destroyLinkList(LinkListNode *head);

