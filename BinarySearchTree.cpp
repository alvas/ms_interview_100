#include <cassert>
#include <iostream>
#include "BinarySearchTree.h"
#include "QuickSort.h"
#include "NormalData.h"
#include "RandomData.h"

using namespace std;

int BST::GetKey()
{
    return key;
}

void BST::SetKey(int k)
{
    key = k;
}

BST *BST::GetParent()
{
    return p;
}

void BST::SetParent(BST *parent)
{
    p = parent;
}

BST *BST::GetLeft()
{
    return left;
}

void BST::SetLeft(BST *l)
{
    left = l;
}

BST *BST::GetRight()
{
    return right;
}

void BST::SetRight(BST *r)
{
    right = r;
}

void InorderTreeWalk(const BST *x)
{
    if (x!= NULL)
    {
        InorderTreeWalk(x->left);
        cout << x->key << endl;
        InorderTreeWalk(x->right);
    }
}

const BST *TreeSearch(const BST *x, const int k)
{
    if (x == NULL || k == x->key)
    {
        return x;
    }

    if (k < x->key)
    {
        return TreeSearch(x->left, k);
    }
    else
    {
        return TreeSearch(x->right, k);
    }
}

const BST *IterativeTreeSearch(const BST *x,  const int k)
{
    while (x != NULL && k != x->key)
    {
        if (k < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    return x;
}

BST *TreeMinimum(BST *x)
{
    while (x->left != NULL)
    {
        x = x->left;
    }

    return x;
}

BST *TreeMaximum(BST *x)
{
    while (x->right != NULL)
    {
        x = x->right;
    }

    return x;
}

BST *TreeSuccessor(BST *x)
{
    if (x->right != NULL)
    {
        return TreeMinimum(x->right);
    }

    BST *y = x->p;

    while (y != NULL && x == y->right)
    {
        x = y;
        y = y->p;
    }

    return y;
}

void TreeInsert(BST *root, BST *z)
{
    BST *y = NULL;
    BST *x = root;

    while (x != NULL)
    {
        y = x;

        if (z->key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    z->p = y;

    if (y == NULL)
    {
        root = z;
    }
    else if (z->key < y->key)
    {
        y->left = z;
    }
    else
    {
        y->right = z;
    }
}

void Transplant(BST *root, BST *u, BST *v)
{
    if (u->p == NULL)
    {
        root = v;
    }
    else if (u == u->p->left)
    {
        u->p->left = v;
    }
    else
    {
        u->p->right = v;
    }

    if (v != NULL)
    {
        v->p = u->p;
    }
}

void TreeDelete(BST *root, BST *z)
{
    if (z->left == NULL)
    {
        Transplant(root, z, z->right);
    }
    else if (z->right == NULL)
    {
        Transplant(root, z, z->left);
    }
    else
    {
        BST *y = TreeMinimum(z->right);

        if (y->p != z)
        {
            Transplant(root, y, y->right);
            y->right = z->right;
            y->right->p = y;
        }

        Transplant(root, z, y);
        y->left = z->left;
        y->left->p = y;
    }
}

int binarySearchRecursive(int A[], int p, int r, int x)
{
    assert(p >= 0 && p <= r);

    if (p > r)
    {
        cerr << "start index is bigger than end index!" << endl;
        exit(-1);
    }

    if (p == r)
    {
        if (A[p] == x)
        {
            return p;
        }
        else
        {
            return -1;
        }
    }

    int mid = p + (r - p) / 2;
    cout << "mid = " << mid << ": p = " << p << "; r = " << r << endl;

    if (A[mid] == x)
    {
        return mid;
    }
    // if mid is equsl to p or r now, but A[mid] is not
    // equal to x, then there is no such x
    else if (mid == p || mid == r)
    {
        return -1;
    }
    else if (A[mid] < x)
    {
        // !!IMPORTANT!! mid could be equal to r, then mid + 1 would be out of bound
        return binarySearchRecursive(A, mid + 1, r, x);
    }
    else
    {
        // !!IMPORTANT!!  mid could be equal to p, then mid - 1 would be out of bound
        return binarySearchRecursive(A, p, mid - 1, x);
    }
}

int binarySearch(int A[], int p, int length, int x)
{
    assert(p >= 0 && length >= 0);

    if (p < 0 || length < 0)
    {
        cerr << "The start index of and the length the array could not be negative!" << endl;
        exit(-1);
    }

    if (length == 0)
    {
        return -1;
    }

    int r = p + length - 1;

    while (p <= r)
    {
        int mid = p + (r - p) / 2;

        if (A[mid] < x)
        {
            p = mid + 1;
        }
        else if (A[mid] > x)
        {
            r = mid - 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

/*
 *  binary search x in vector v
 */
int binarySearch(const vector<int> &v, int x)
{
    // Handle emppty vector case.
    // Can't rely on start <= finish condition to
    // handle this special case. Otherwise, *middle
    // would reference to invalid data.
    if (v.size() == 0)
    {
        return -1;
    }

    vector<int>::const_iterator start = v.begin();
    vector<int>::const_iterator finish = v.end();

    // !! Don't forget the equal case!!
    while (start <= finish)
    {
        vector<int>::const_iterator middle = (finish - start) / 2 + start;

#ifdef DEBUG
        cout << "middle = " << middle - v.begin() << endl;
#endif
        if (*middle == x)
        {
            return middle - v.begin();
        }
        else if (*middle < x)
        {
            start = middle + 1;
        }
        else if (*middle > x)
        {
            finish = middle - 1;
        }
    }

    return -1;
}

#ifndef EXPORTED
int main()
{
    int A[LENGTH] = {0};
    initializeArray(A, LENGTH);
    QuickSort(A, 0, LENGTH - 1);
//    printArray(A, LENGTH);
//    int index = binarySearch(A, 0, LENGTH - 1, 1153);
    vector<int> v(A, A + LENGTH);
//    initializeVector(v, LENGTH);
    printVector(v);
    int index = binarySearch(v, 1272);
    cout << index << endl;
    return 0;
}
#endif
