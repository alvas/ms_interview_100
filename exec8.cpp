#include <cassert>
#include <iostream>

using namespace std;

struct Node
{
    int a;
    Node *next;
};

Node *reverseRecursive(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    else if (head->next == NULL)
    {
        return head;
    }

    Node *p = reverseRecursive(head->next);
    head->next->next = head;
    // Don't forget to set the first element next pointer to null
    head->next = NULL;
    return p;
}

Node *reverse(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    else if (head->next == NULL)
    {
        return head;
    }

    Node *p1 = NULL;
    Node *p2 = head;
    Node *p3 = head->next;

    while (p3 != NULL)
    {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }

    // Don't forget to set the next pointer of the last element
    p2->next = p1;

    return p2;
}

void reverseString(char *str, int p, int r)
{
    if (str == NULL)
    {
        return;
    }
    else if (p < 0 || r < 0 || r < p)
    {
        assert(p >= 0 && r >= 0 && r > p);
        return;
    }

    while (p < r)
    {
        char c = str[p];
        str[p] = str[r];
        str[r] = c;
        p++;
        r--;
    }
}

int main()
{
    int count = 10;
    Node *head = NULL, *ptr = NULL;

    while (count--)
    {
        Node *p = new Node;
        p->a = count;
        p->next = NULL;

        if (ptr != NULL)
        {
            // Don't forget to set the next
            ptr->next = p;
        }
        else
        {
            head = p;
        }

        // Don't forget to reset the next
        ptr = p;
    }

    ptr = reverse(head);
//    ptr = reverseRecursive(head);
    cout << "Print the list:" << endl;

    while (ptr != NULL)
    {
        cout << ptr->a << endl;
        Node *p = ptr;
        // Don't forget to move the to next
        ptr = ptr->next;
        delete p;
    }

    char abc[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

//    reverseString(abc, 0, 6);
    reverseString(abc, 2, 4);
    reverseString(abc, 0, 4);

    for (int i = 0; i < 7; ++i)
    {
        cout << abc[i];
    }

    cout << endl;

    return 0;
}

