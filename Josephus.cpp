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
        LinkListNode *prev = NULL;

        for (int i = 0; i < k - 1 && list.current != NULL; ++i)
        {
            prev = list.current;
            list.current = list.current->next;
        }
        
        LinkListNode *p = list.current;

        if (p != NULL)
        {
            list.current = p->next;
            prev->next = list.current;
            cout << "delete node " << p->key << endl;
            delete p;
            p = NULL;
        }
        
        printCircularLinkList(list);
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
