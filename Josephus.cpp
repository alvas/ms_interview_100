#include <iostream>
#include "CircularLinkList.h"
#include "NormalData.h"

using namespace std;

const int N = 7;
const int K = 3;

void Josephus(int n, int k)
{
    int fn = 0;

    for (int i = 2; i <= n; ++i)
    {
        fn = (fn + k) % i;

#ifdef DEBUG
        cout << "i = " << i << "; fn = " << fn << endl;
#endif
    }

    cout << "The solution of Josephus problem with N = " << n << "[0, N - 1], K = " << k << " is " << fn << "." << endl;
}

void JosephusLinkList(int n, int k)
{
    vector<int> v;
    initializeIndexVector(v, n);
    CircularLinkList list(v);

    while (list.current != NULL)
    {
        // Because this is not bidirection link list, we need to keep
        // the previous node pointer in order to link it to the node
        // after the deleted node.
        LinkListNode *prev = NULL;

#ifdef DEBUG
        printCircularLinkList(list);
#endif

        for (int i = 0; i < k - 1 && list.current != NULL; ++i)
        {
            prev = list.current;
            list.current = list.current->next;
        }
        
        LinkListNode *p = list.current;

        if (p != NULL)
        {
            list.current = p->next;

            // If the prevous node is the current node, there is only
            // one node in the circular list. We need to set the circular
            // link list to empty after we delete the last node on the list.
            if (prev != p)
            {
                prev->next = list.current;
            }
            else
            {
                list.current = NULL;
            }

#ifdef DEBUG
            cout << "Delete node " << p->key << endl << endl;;
#endif
            delete p;
        }
    }
}

#ifndef EXPORTED
int main()
{
//    Josephus(N, K);
    JosephusLinkList(N, K);
    return 0;
}
#endif
