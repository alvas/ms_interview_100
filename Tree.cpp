#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include "Tree.h"

using namespace std;

TreeNode *InitializeBST(const vector<int> &v)
{
    TreeNode *root = NULL, *p = NULL;
    cout << "Initializing:" << endl;

    for (int i = 0; i < 7; ++i)
    {
        TreeNode *node = new TreeNode;
        node->value = v[i];
        node->left = node->right = NULL;
        cout << "Creating node[" << i << "] = " << v[i] << endl;

        if (root == NULL)
        {
            root = node;
            p = node;
        }
        else
        {
            while (p != NULL)
            {
                if (p->value > node->value)
                {
                    if (p->left != NULL)
                    {
                        p = p->left; 
                    }
                    else
                    {
                        p->left = node;
                        // INFO: don't forget to break from here after the node is inserted
                        break;
                    }
                }
                else
                {
                    if (p->right != NULL)
                    {
                        p = p->right;
                    }
                    else
                    {
                        p->right = node;
                        // INFO: don't forget to break from here after the node is inserted
                        break;
                    }
                }
            }
        }
    }

    return root;
}

void DFT(TreeNode *p)
{
    if (p == NULL)
    {
        return;
    }
    else
    {
        if (p->left != NULL)
        {
            DFT(p->left);
        }

        cout << p->value << endl;

        if (p->right != NULL)
        {
            DFT(p->right);
        }
    }
}

void DFTWithStack(TreeNode *p)
{
    if (p == NULL)
    {
        return;
    }

    stack<TreeNode *> treeNodeStack;

    treeNodeStack.push(p);

    do
    {
        if (p->left != NULL)
        {
            p = p->left;
            treeNodeStack.push(p);
        }
        else
        {
            // p node without left child
            p = treeNodeStack.top();
            cout << p->value << endl;
            treeNodeStack.pop();

            // p node's parent is on the stack
            if (!treeNodeStack.empty())
            {
                p = treeNodeStack.top();
                cout << p->value << endl;
                treeNodeStack.pop();
            }

            // when a right child is pushed to the stack, its
            // parent has already been poped out of the stack
            if (p->right != NULL)
            {
                p = p->right;
                treeNodeStack.push(p);
            }
        }
    } while (!treeNodeStack.empty());
}

void BFT(TreeNode *p)
{
    queue<TreeNode *> treeQueue;
    treeQueue.push(p);
    
    while (!treeQueue.empty())
    {
        p = treeQueue.front();
        treeQueue.pop();
        cout << p->value << endl;

        if (p->left != NULL)
        {
            treeQueue.push(p->left);
        }

        if (p->right != NULL)
        {
            treeQueue.push(p->right);
        }
    }
}

void DestroyTree(TreeNode *p)
{
    if (p == NULL)
    {
        return;
    }
    else
    {
        if (p->left != NULL)
        {
            DestroyTree(p->left);
        }
        
        if (p->right != NULL)
        {
            DestroyTree(p->right);
        }

        cout << "Destropying node = " << p->value << endl;
        delete p;
    }
}

#ifndef EXPORTED
int main()
{
    int num[7] = {10, 6, 14, 4, 8, 12, 16};
    vector<int> v(num, num + 7);
    TreeNode *root = InitializeBST(v);
    cout << "Finish building BST" << endl;

    DFT(root);
    //DFTWithStack(root);
    //BFT(root);

    //TreeNode *biggest = FindBiggestInTree(root);

    //if (biggest != NULL)
    //{
    //    cout << "The biggest node is " << biggest->value << endl;
    //}

    //TreeNode *smallest = FindSmallestInTree(root);

    //if (smallest != NULL)
    //{
    //    cout << "The smallest node is " << smallest->value << endl;
    //}

    DestroyTree(root);

    //TreeToLinkList(root);
    //TreeToLinkListWithRecursion(root);


    return 0;
}
#endif
