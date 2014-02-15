#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct BSTreeNode
{
    int m_nValue;
    BSTreeNode *m_pLeft;
    BSTreeNode *m_pRight;
};

/* BST
 *
 *               10
 *             /    \
 *            6     14
 *          /  \   /  \
 *         4   8  12  16
 *
 */

static int num[7] = {10, 6, 14, 4, 8, 12, 16};

BSTreeNode *InitializeBST()
{
    BSTreeNode *head = NULL, *p = NULL;
    cout << "Initializing:" << endl;

    for (int i = 0; i < 7; ++i)
    {
        BSTreeNode *node = new BSTreeNode;
        node->m_nValue = num[i];
        node->m_pLeft = node->m_pRight = NULL;
        cout << "Creating node[" << i << "] = " << num[i] << endl;

        if (head == NULL)
        {
            head = node;
        }
        else
        {
            // INFO: the first time, head not should not come here, since it is the same node
            p = head;

            do
            {
                if (p->m_nValue > node->m_nValue)
                {
                    if (p->m_pLeft != NULL)
                    {
                        p = p->m_pLeft; 
                    }
                    else
                    {
                        p->m_pLeft = node;
                        // INFO: don't forget to break from here after the node is inserted
                        break;
                    }
                }
                else
                {
                    if (p->m_pRight != NULL)
                    {
                        p = p->m_pRight;
                    }
                    else
                    {
                        p->m_pRight = node;
                        // INFO: don't forget to break from here after the node is inserted
                        break;
                    }
                }
            } while (p != NULL);
        }
    }

    return head;
}

void DFS(BSTreeNode *p)
{
    if (p == NULL)
    {
        return;
    }
    else
    {
        if (p->m_pLeft != NULL)
        {
            DFS(p->m_pLeft);
        }

        cout << p->m_nValue << endl;

        if (p->m_pRight != NULL)
        {
            DFS(p->m_pRight);
        }
    }
}

void DFSWithStack(BSTreeNode *p)
{
    if (p == NULL)
    {
        return;
    }

    stack<BSTreeNode *> treeNodeStack;

    // p always points to the top of the stack
    treeNodeStack.push(p);

    do
    {
        p = treeNodeStack.top();

        if (p->m_pLeft != NULL)
        {
            p = p->m_pLeft;
            treeNodeStack.push(p);
        }
        else
        {
            cout << p->m_nValue << endl;
            treeNodeStack.pop();

            if (!treeNodeStack.empty())
            {
                p = treeNodeStack.top();

                if (p->m_pRight != NULL)
                {
                    cout << p->m_nValue << endl;
                    treeNodeStack.pop();
                    p = p->m_pRight;
                    treeNodeStack.push(p);
                }
                else
                {
                    cout << p->m_nValue << endl;
                    treeNodeStack.pop();
                }
            }
        }
    } while (!treeNodeStack.empty());
}

void WFS(BSTreeNode *p)
{
    queue<BSTreeNode *> treeQueue;
    treeQueue.push(p);
    
    while (!treeQueue.empty())
    {
        p = treeQueue.front();
        treeQueue.pop();
        cout << p->m_nValue << endl;

        if (p->m_pLeft != NULL)
        {
            treeQueue.push(p->m_pLeft);
        }

        if (p->m_pRight != NULL)
        {
            treeQueue.push(p->m_pRight);
        }
    }
}

BSTreeNode * FindSmallestInSubTree(BSTreeNode *p)
{
    BSTreeNode *smallestNode = NULL;

    if (p == NULL)
    {
        return smallestNode;
    }
    else if (p->m_pLeft == NULL)
    {
        return p; 
    }
    else
    {
        do
        {
            smallestNode = p->m_pLeft;
            p = p->m_pLeft;
        } while (p->m_pLeft != NULL);

        return smallestNode;
    }
}

BSTreeNode *FindBiggestInSubTree(BSTreeNode *p)
{
    BSTreeNode *biggestNode = NULL;

    if (p == NULL)
    {
        return biggestNode;
    }
    else if (p->m_pRight == NULL)
    {
        return p;
    }
    else
    {
        do
        {
            biggestNode = p->m_pRight;
            p = p->m_pRight;
        } while (p->m_pRight != NULL);

        return biggestNode;
    }
}

void TreeToLinkList(BSTreeNode *p)
{
}

void DestroyBSTree(BSTreeNode *p)
{
    if (p == NULL)
    {
        return;
    }
    else
    {
        if (p->m_pLeft != NULL)
        {
            DestroyBSTree(p->m_pLeft);
        }
        
        if (p->m_pRight != NULL)
        {
            DestroyBSTree(p->m_pRight);
        }

        cout << "Destropying node = " << p->m_nValue << endl;
        delete p;
    }
}

int main()
{
    BSTreeNode *head = InitializeBST();
    cout << "Finish building BST" << endl;

    //DFS(head);
    //DFSWithStack(head);
    //WFS(head);

    //BSTreeNode *biggest = FindBiggestInSubTree(head);

    //if (biggest != NULL)
    //{
    //    cout << "The biggest node is " << biggest->m_nValue << endl;
    //}

    //BSTreeNode *smallest = FindSmallestInSubTree(head);

    //if (smallest != NULL)
    //{
    //    cout << "The smallest node is " << smallest->m_nValue << endl;
    //}
    TreeToLinkList(head);

    DestroyBSTree(head);
    return 0;
}
