#include <iostream>
#include <queue>

using namespace std;

struct BSTreeNode
{
    int m_nValue;
    BSTreeNode *m_pLeft;
    BSTreeNode *m_pRight;
};

static int num[7] = {10, 6, 14, 4, 8, 12, 16};

static BSTreeNode *head = NULL;

void InitializeBST()
{
    BSTreeNode *p = NULL;
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

void WFS(BSTreeNode *p)
{
    std::queue<BSTreeNode *> treeQueue;

    treeQueue.push(p);
    
    while (!treeQueue.empty())
    {
        BSTreeNode *node = treeQueue.front();
        treeQueue.pop();
        cout << node->m_nValue << endl;

        if (node->m_pLeft != NULL)
        {
            treeQueue.push(node->m_pLeft);
        }

        if (node->m_pRight != NULL)
        {
            treeQueue.push(node->m_pRight);
        }
    }
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
    InitializeBST();
    cout << "Finish building BST" << endl;
    //DFS(head);
    WFS(head);
    DestroyBSTree(head);
    return 0;
}
