class LinkList
{
    public:
        LinkList(int);

        int key;
        LinkList *next;
};

class DoubleLinkList: public LinkList
{
    public:
        DoubleLinkList(int);

        DoubleLinkList *prev;
};
