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
    BSTreeNode *root = NULL, *p = NULL;
    cout << "Initializing:" << endl;

    for (int i = 0; i < 7; ++i)
    {
        BSTreeNode *node = new BSTreeNode;
        node->m_nValue = num[i];
        node->m_pLeft = node->m_pRight = NULL;
        cout << "Creating node[" << i << "] = " << num[i] << endl;

        if (root == NULL)
        {
            root = node;
        }
        else
        {
            // INFO: the first time, root not should not come here, since it is the same node
            p = root;

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

    return root;
}

void DFT(BSTreeNode *p)
{
    if (p == NULL)
    {
        return;
    }
    else
    {
        if (p->m_pLeft != NULL)
        {
            DFT(p->m_pLeft);
        }

        cout << p->m_nValue << endl;

        if (p->m_pRight != NULL)
        {
            DFT(p->m_pRight);
        }
    }
}

void DFTWithStack(BSTreeNode *p)
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

void BFT(BSTreeNode *p)
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

BSTreeNode * FindSmallestInTree(BSTreeNode *p)
{
    if (p == NULL)
    {
        return NULL;
    }
    else if (p->m_pLeft == NULL)
    {
        return p; 
    }
    else
    {
        do
        {
            p = p->m_pLeft;
        } while (p->m_pLeft != NULL);

        return p;
    }
}

BSTreeNode *FindBiggestInTree(BSTreeNode *p)
{
    if (p == NULL)
    {
        return NULL;
    }
    else if (p->m_pRight == NULL)
    {
        return p;
    }
    else
    {
        do
        {
            p = p->m_pRight;
        } while (p->m_pRight != NULL);

        return p;
    }
}

// TODO: Haven't check this funciton very carfully and it is not used yet.
BSTreeNode *FindParentOfSmallest(BSTreeNode *p)
{
    if (p == NULL)
    {
        return NULL;
    }
    else if (p->m_pLeft == NULL)
    {
        return NULL;
    }
    else
    {
        while (p->m_pLeft->m_pLeft != NULL)
        {
            p = p->m_pLeft; 
        }

        return p;
    }
}

BSTreeNode *FindParentOfNode(BSTreeNode *root, BSTreeNode *p)
{
    BSTreeNode *node = root;
    
    // INFO: Check the case when finding the parent of the root
    if (node == NULL || p == NULL || node == p)
    {
        return NULL;
    }
    // INFO: There is only an orphan node, p is not in the tree
    else if (node->m_pLeft == NULL && node->m_pRight == NULL)
    {
        return NULL;
    }
    else
    {
        while (node != NULL && node->m_pLeft != p && node->m_pRight != p)
        {
            if (node->m_nValue > p->m_nValue)
            {
                node = node->m_pLeft;
            }
            else
            {
                node = node->m_pRight;
            }
        }

        return node;
    }
}

void TreeToLinkList(BSTreeNode *p)
{
    BSTreeNode *smallest = FindSmallestInTree(p);
    BSTreeNode *root = smallest, *tail = smallest;

    while (smallest != NULL)
    {
        BSTreeNode *parent = FindParentOfNode(p, smallest);

        if (parent != NULL)
        {
            if (parent->m_pLeft != NULL)
            {
                // INFO: Adjust parent structure before we modify the smallest
                if (smallest->m_pRight == NULL)
                {
                    parent->m_pLeft = NULL;
                }
                else
                {
                    parent->m_pLeft = smallest->m_pRight;
                }

                // INFO: Don't overwrite the left pointer of the first node in the link list
                if (smallest != root)
                {
                    smallest->m_pLeft = tail;
                }

                tail->m_pRight = smallest;
                tail = smallest;
                smallest = FindSmallestInTree(p);
            }
        }
        else
        {
            // We find the root of the BSTree

            // INFO
            if (smallest->m_pRight != NULL)
            {
                smallest->m_pLeft = tail;
                tail->m_pRight = smallest;
                tail = smallest;
                p = smallest->m_pRight;
                smallest = FindSmallestInTree(p);
            }
            else
            {
                // INFO: Here we find the last node in the BSTree and break
                smallest->m_pLeft = tail;
                tail->m_pRight = smallest;
                smallest = NULL;
            }
        }
    }

    if (root != NULL)
    {
        BSTreeNode *node = root;
        cout << "Start to print the link list from the left:" << endl;

        while (node != NULL)
        {
            cout << node->m_nValue << endl;
            tail = node;
            node = node->m_pRight;
        }

        node = tail;
        cout << "Start to print the link list from the right:" << endl;

        while (node != NULL)
        {
            cout << node->m_nValue << endl;
            node = node->m_pLeft;
        }
    }
}

// INFO: head and tail are a reference to a pointer
// IMPORTANT: there is no such thing as a pointer to a reference 
void TreeToList(BSTreeNode* &head, BSTreeNode* &tail, BSTreeNode *root)
{
    BSTreeNode *left = NULL, *right = NULL;

    if (root == NULL)
    {
        head = NULL;
        tail = NULL;
        return;
    }

    TreeToList(head, left, root->m_pLeft);
    TreeToList(right, tail, root->m_pRight);

    if (left != NULL)
    {
        left->m_pRight = root;
        root->m_pLeft = left;
    }
    else
    {
        head = root;
    }

    if (right != NULL)
    {
        root->m_pRight = right;
        right->m_pLeft = root;
    }
    else
    {
        tail = root;
    }
}

void TreeToLinkListWithRecursion(BSTreeNode *root)
{
    BSTreeNode *head = NULL, *tail = NULL;

    TreeToList(head, tail, root);
    
    BSTreeNode *node = head;
    cout << "Start to print the link list from the left:" << endl;

    while (node != NULL)
    {
        cout << node->m_nValue << endl;
        node = node->m_pRight;
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

// Since we have destroy the BSTree structure and change it to Link list, we need a different mechanism to 
// clean up the memory
void DestroyLinkList(BSTreeNode *p)
{
    if (p == NULL)
    {
        return;
    }
    else
    {
        while (p != NULL)
        {
            BSTreeNode *node = p;
            p = p->m_pLeft;
            delete node;
        }
    }
}

int main()
{
    BSTreeNode *root = InitializeBST();
    cout << "Finish building BST" << endl;

    //DFT(root);
    //DFTWithStack(root);
    //BFT(root);

    //BSTreeNode *biggest = FindBiggestInTree(root);

    //if (biggest != NULL)
    //{
    //    cout << "The biggest node is " << biggest->m_nValue << endl;
    //}

    //BSTreeNode *smallest = FindSmallestInTree(root);

    //if (smallest != NULL)
    //{
    //    cout << "The smallest node is " << smallest->m_nValue << endl;
    //}

    //DestroyBSTree(root);

    //TreeToLinkList(root);
    TreeToLinkListWithRecursion(root);

    DestroyLinkList(root);

    return 0;
}

