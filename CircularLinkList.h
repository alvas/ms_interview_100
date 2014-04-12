#include <vector>
#include "LinkList.h"

class CircularLinkList
{
    public:
        CircularLinkList(const vector<int>);
        ~CircularLinkList();
        LinkListNode *GetCurrent();

        LinkListNode *current;
};

void printCircularLinkList(CircularLinkList &list);
