#include <iostream>
#include <queue>
#include <stack>

#include "NormalData.h"
#include "Tree.h"

using namespace std;


TreeNode *InitializeBST(const vector<int> &v)
{
    TreeNode *root = NULL;
    cout << "Initializing:" << endl;

    if (v.empty())
    {
        return root;
    }

    root = new TreeNode(v[0]);
    cout << "Creating node[" << 0 << "] = " << v[0] << endl;

    for (int i = 1; i < v.size(); ++i)
    {
        TreeNode *node = new TreeNode(v[i]);
        cout << "Creating node[" << i << "] = " << v[i] << endl;
        TreeNode *p = root;

        while (p != NULL)
        {
            if (p->val > node->val)
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

        cout << p->val<< endl;

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
            cout << p->val << endl;
            treeNodeStack.pop();

            // p node's parent is on the stack
            if (!treeNodeStack.empty())
            {
                p = treeNodeStack.top();
                cout << p->val << endl;
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
        cout << p->val << endl;

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
    else {
        if (p->left != NULL)
        {
            DestroyTree(p->left);
        }
        
        if (p->right != NULL)
        {
            DestroyTree(p->right);
        }

        cout << "Destropying node = " << p->val << endl;
        delete p;
    }
}

// Using reference to pointer
void ReBuildTreeFromPreIn(int *preOrder, int *inOrder, int nTreeLen, TreeNode *&root)
{
    if (preOrder == NULL || inOrder == NULL || nTreeLen <= 0)
    {
        root = NULL;
        return;
    }

    int tmp = preOrder[0];
    int i = 0;

    //cout << "Node: " << tmp << endl;
    
    // i will be index of node following the node which equals tmp
    while (i < nTreeLen && inOrder[i++] != tmp)
    {
        ;
    }

    //cout << "index: " << i << endl;

    root = new TreeNode(tmp);

    // Be careful about the tree len here!!
    // i -1  is the number of node on left child tree
    // Use preOrder array to calculate the position.
    ReBuildTreeFromPreIn(preOrder + 1, inOrder, i - 1, root->left);
    ReBuildTreeFromPreIn(preOrder + i, inOrder + i, nTreeLen - i, root->right);
}


void ReBuildTreeFromPreOrder(TreeNode *&root, const vector<string> &v, int &index)
{
    if (index < 0 || index > v.size())
    {
        return;
    }

    if (v[index] == "#")
    {
        index++;
        return;
    }
    else
    {
        int num = atoi(v[index].c_str());
        index++;
        root = new TreeNode(num);
        cout << "Creating node: " << num << endl;
        ReBuildTreeFromPreOrder(root->left, v, index);
        ReBuildTreeFromPreOrder(root->right, v, index);
    }
}

// Construct tree from preOrder and InOrder using stack
// The first time a node is accessed in preOrder, it will be inserted to tree.
// addRightChild will decide whehter insert it as left child or right child.
// 1. push the first node onto stack, set it as cur, and set addRightChild to false
// 2. if stack is empty or top node on stack value is not equal to inOrder node,
//        if addRightChild is false, add the next preOrder node to the LEFT child of cur
//        if addRightChild is true, set addRightChild to false, add the next preOrder node
//             to the right child of cur
// 3. if stack is not empty and top node on stack value equals to inOrder node
//       pop the top node from stack, set it as cur, set addRightChild to true, move on inOrder
void ReBuildTreeFromPreIn2(int *preOrder, int *inOrder, int nTreeLen, TreeNode *&root)
{
    if (preOrder == NULL || inOrder == NULL || nTreeLen <= 0)
    {
        root = NULL;
        return;
    }

    stack<TreeNode *> s;
    int pdx = 0, idx = 0;
    root = new TreeNode(preOrder[pdx++]);
    TreeNode *cur = root;
    
    // !! Remember to push the root to the stack!!
    s.push(cur);

    // Indicator whether to add the node as a right child
    bool addRightChild = false;

    while (pdx < nTreeLen)
    {
        // If the stack is not empty, and the top node equals to the inOrder node,
        // set cur to top node, pop the node, and see set the addRightChild to true.
        // The next node added is a right node of cur node.
        if (!s.empty() && s.top()->val == inOrder[idx])
        {
            cur = s.top();
            s.pop();
            addRightChild = true;
            idx++;
        }
        else
        {
            // If stack is empty or top node is not equal to inOrder node
            // add node and push it to stack
            if (!addRightChild)
            {
                cur->left = new TreeNode(preOrder[pdx++]);
                cur = cur->left;
                s.push(cur);
            }
            else
            {
                addRightChild = false;
                cur->right = new TreeNode(preOrder[pdx++]);
                cur = cur->right;
                s.push(cur);
            }
        }
    }
}

void ReBuildTreeFromPrePost(int *preOrder, int *postOrder, int nTreeLen, TreeNode *&root)
{
    if (preOrder == NULL || postOrder == NULL || nTreeLen <= 0)
    {
        root = NULL;
        return;
    }

    int i = 0;

    while (i < nTreeLen && postOrder[i++] != preOrder[1])
    {
        ;
    }

    root = new TreeNode(preOrder[0]);

    // i is the number of node on left child tree
    // Use preOrder array to calculate the position.
    ReBuildTreeFromPrePost(preOrder + 1, postOrder, i, root->left);
    ReBuildTreeFromPrePost(preOrder + i + 1, postOrder + i, nTreeLen - i - 1, root->right);
}

// The first time a node is accessed in preOrder, it will be inserted to tree.
// 1. push root onto stack and set addRightChild to false, set cur to root
// 2. if stack is empty or top node is not equal to postOrder
//         if addRightChild is false, add next preOrder node to left child of cur, set cur to its left child
//              push cur to stack
//         if addRightChild is true, set it to false, add next preOrder node to right child of cur
//              set cur to its right child, push cur to stack
// 3. if stack is not empty and top node equals to postOrder node
//        pop the top node, set cur to this top node, set addRightChild to true, advance postOrder 
void ReBuildTreeFromPrePost2(int *preOrder, int *postOrder, int nTreeLen, TreeNode *&root)
{
    if (preOrder == NULL || postOrder == NULL || nTreeLen <= 0)
    {
        root = NULL;
        return;
    }

    stack<TreeNode *> s;
    int pdx = 0, idx = 0;
    root = new TreeNode(preOrder[pdx++]);
    TreeNode *cur = root;
    
    s.push(cur);

    // Indicator whether to add the node as a right child
    bool addRightChild = false;

    while (pdx < nTreeLen)
    {
        if (!s.empty() && s.top()->val == postOrder[idx])
        {
            s.pop();
            cur = s.top();
            addRightChild = true;
            idx++;
        }
        else
        {
            if (!addRightChild)
            {
                cur->left = new TreeNode(preOrder[pdx++]);
                cur = cur->left;
                s.push(cur);
            }
            else
            {
                addRightChild = false;
                cur->right = new TreeNode(preOrder[pdx++]);
                cur = cur->right;
                s.push(cur);
            }
        }
    }
}

void ReBuildTreeFromInPost(int *inOrder, int *postOrder, int nTreeLen, TreeNode *&root)
{
    if (inOrder == NULL || postOrder == NULL || nTreeLen <= 0)
    {
        root = NULL;
        return;
    }

    int i = nTreeLen;
    int tmp = postOrder[nTreeLen - 1];

    while (i > 0 && inOrder[--i] != tmp)
    {
        ;
    }


    root = new TreeNode(tmp);

    // i is the number of node on left child tree
    // Use inOrder array to calculate the position.
    ReBuildTreeFromInPost(inOrder, postOrder, i, root->left);
    ReBuildTreeFromInPost(inOrder + i + 1, postOrder + i, nTreeLen - i - 1, root->right);
}

void ReBuildTreeFromInPost2(int *inOrder, int *postOrder, int nTreeLen, TreeNode *&root)
{
    if (inOrder == NULL || postOrder == NULL || nTreeLen <= 0)
    {
        root = NULL;
        return;
    }

    stack<TreeNode *> s;
    int idx = nTreeLen - 1, podx = nTreeLen - 1;
    root = new TreeNode(postOrder[podx--]);
    bool addLeftChild = false;
    TreeNode *cur = root;
    s.push(cur);

    // reverse order to access node
    while (podx >= 0)
    {
        if (!s.empty() && s.top()->val == inOrder[idx])
        {
            // !! IMPORTANT, get the top node first, then pop it out
            cur = s.top();
            s.pop();
            addLeftChild = true;
            --idx;
        }
        else
        {
            if (!addLeftChild)
            {
                cur->right = new TreeNode(postOrder[podx--]);
                cur = cur->right;
                s.push(cur);
            }
            else
            {
                addLeftChild = false;
                cur->left = new TreeNode(postOrder[podx--]);
                cur = cur->left;
                s.push(cur);
            }
        }
    }
}

// caller invokes this function with INT_MIN, INT_MAX for min and max
void ReBuildBSTree(int min, int max, TreeNode *&p, const int *address)
{
    if (address == NULL)
    {
        return;
    }

    if (*address > min && *address < max)
    {
        int val = *address;
        p = new TreeNode(val);

        address++;

        ReBuildBSTree(min, val, p->left, address);
        ReBuildBSTree(val, max, p->right, address);
    }
}

void CleanUp(TreeNode *&root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left != NULL)
    {
        CleanUp(root->left);
    }

    if (root->right != NULL)
    {
        CleanUp(root->right);
    }

    cout << "Freeing node: " << root->val << endl;
    delete root;
    root = NULL;
}

void CleanUp2(TreeNode *&root)
{
    if (root == NULL)
    {
        return;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *p = q.front();
        q.pop();

        if (p->left != NULL)
        {
            q.push(p->left);
        }

        if (p->right != NULL)
        {
            q.push(p->right);
        }

        //cout << "Freeing node: " << p->val << endl;
        delete p;
    }
}

void BuildPreOrderVector(TreeNode * const root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    v.push_back(root->val);
    BuildPreOrderVector(root->left, v);
    BuildPreOrderVector(root->right, v);
}

void BuildPreOrderVector(TreeNode * const root, vector<string> &v)
{
    if (root == NULL)
    {
        v.push_back("#");
    }
    else
    {
        v.push_back(std::to_string(root->val));
        BuildPreOrderVector(root->left, v);
        BuildPreOrderVector(root->right, v);
    }
}

// 1. visit root and push it onto stack, set cur to its left child
// 2. if cur is not NULL, visit it and push it onto stack, set cur to its left child
// 3. if cur is NULL, set cur to the right child of top node, pop the top node from stack
void BuildPreOrderVector2(TreeNode * const root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }


    stack<TreeNode *> s;

    // Pre order, visit node here
    v.push_back(root->val);

    // push the root node into stack
    // and make cur as left child of root
    TreeNode *cur = root;

    s.push(cur);
    cur = cur->left;

    // whenever pushing a node to stack,
    // its value has been added to vector
    // and its left child is accessed next
    // whenever poping a node from stack,
    // since its left child has been access,
    // access its right child next
    while (!s.empty() || cur != NULL)
    {
        // if cur has left child, push it to stack
        // and change cur to its left child
        if (cur != NULL)
        {
            // Pre order, visit node here
            v.push_back(cur->val);
            s.push(cur);
            cur = cur->left;
        }
        else
        {
            // when cur doesn't have any left child
            // pop the top node from stack
            // try to push its right child to the stack
            // if it isn't null
            cur = s.top();
            s.pop();
            cur = cur->right;
        }
    }
}

// Utilize a temporary link from preceding node of cur node in In-order traverse to cur node to get back
// to cur node after finishing traversing left child subtree.
// 1. if the left child of cur node is empty, visit cur node and set cur to its right child
// 2. if left child of cur node is not empty, set prev to preceding node of cur node in In-order traverse
//        if right child of prev is empty, set its right child to cur, and visit cur node, set cur to its left child
//        if right child of prev is not empty, set it to empty to remove the linke, set cur to its right child
void BuildPreOrderVector3(TreeNode * const root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    TreeNode *cur = root, *prev = NULL;

    while (cur != NULL)
    {
        // If cur node doesn't have left child, visit it and
        // set its right child as cur node.
        if (cur->left == NULL)
        {
            v.push_back(cur->val);
            cur = cur->right;
        }
        else
        {
            // If the cur node has left child, set it as pre
            prev = cur->left;

            // find the preceding node of cur node in In-order traverse
            while (prev->right != NULL && prev->right != cur)
            {
                prev = prev->right;
            }

            // if the preceding node of cur node in In-order traverse doesn't have right child,
            // the link hasn't been established yet, link its right child to cur.
            // set cur to its left child
            if (prev->right == NULL)
            {
                prev->right = cur;

                // visit node here Pre-Order
                v.push_back(cur->val);
                cur = cur->left;
            }
            // If its right child has pointed to cur, and we traverse back to it again, break the link
            // set cur to its right child.
            else
            {
                // when it breaks its left subtree link to cur, cut is reset to the root node of its
                // right subtree.
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
}

void BuildInOrderVector(TreeNode * const root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    BuildInOrderVector(root->left, v);
    v.push_back(root->val);
    BuildInOrderVector(root->right, v);
}

// 1. push root node onto stack, set cur to its left child
// 2. if cur is not NULL, push it onto stack and set cur to its left child
// 3. if cur is NULL, get top node from stack and set it to cur,
//        visit cur, set cur to its right child, pop the top node from stack
void BuildInOrderVector2(TreeNode * const root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    stack<TreeNode *> s;

    TreeNode *cur = root;
    s.push(cur);
    cur = root->left;

    while (!s.empty() || cur != NULL)
    {
        if (cur != NULL)
        {
            s.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = s.top();
            s.pop();
            
            // In order visit node here.
            v.push_back(cur->val);
            cur = cur->right;
        }
    }
}

void BuildInOrderVector3(TreeNode * const root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    TreeNode *cur = root, *prev = NULL;

    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            v.push_back(cur->val);
            cur = cur->right;
        }
        else
        {
            prev = cur->left;

            while (prev->right != NULL && prev->right != cur)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                prev->right = NULL;

                // visit cur here In-Order
                v.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
}

void BuildPostOrderVector(TreeNode * const root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    BuildPostOrderVector(root->left, v);
    BuildPostOrderVector(root->right, v);
    v.push_back(root->val);
}

// 1. push root to stack, set cur to left child of root
// 2. if cur is not empty, push cur onto stack and set cur to its left child
// 3. if cur is empty, get the top node from stack, 
//       if right child of top node is not empty and its right child is not equal to prev
//            set cur to right child of top, push cur to stack, and set cur to its left child
//       if right child of top node is empty or is equal to prev
//            visit the top node, set prev to top node, pop top node from stack
void BuildPostOrderVector2(TreeNode * const root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    stack<TreeNode *> s;
    TreeNode *cur = root;

    // Need an assistant variable prev to keep track of whether we have visited
    // right child of top node. If the right child of the top node was just 
    // poped out of stack, we need to pop the top node from the stack, instead of
    // push its right child onto the stack again.
    TreeNode *prev = NULL;

    s.push(cur);
    cur = cur->left;

    while (!s.empty())
    {
        if (cur != NULL)
        {
            s.push(cur);
            cur = cur->left;
        }
        else
        {
            TreeNode *top = s.top();

            // !! IMPORTANT, need to check whether the right child of top node
            //               has been visited or not, before push it onto stack
            if (top->right != NULL && top->right != prev)
            {
                cur = top->right;
                s.push(cur);
                cur = cur->left;
            }
            else
            {
                s.pop();
                v.push_back(top->val);
                prev = top;
            }
        }
    }
}

void reverseLink(TreeNode *from, TreeNode *to)
{
    if (from == to)
    {
        return;
    }

    TreeNode *x = from, *y = from->right, *z = NULL;

    while (x != to)
    {
        z = y->right;
        y->right = x;
        x = y;
        y = z;
    }
}

void visitNode(TreeNode *from, TreeNode *to, vector<int> &v)
{
    reverseLink(from, to);

    TreeNode *p = to;

    while (1)
    {
        v.push_back(p->val);

        if (p == from)
        {
            break;
        }

        p = p->right;
    }

    reverseLink(to, from);
}

// 1. create an auxililiary virtual root node and set its left child to root, set cur to virutal root
// 2. if cur is not empty, and cur's left child is NULL, set cur to its right child
// 3. if cur's left child is not NULL, set prev to cur's left child,
//        find the preceeding node of cur in In-Order traverse, and set it to prev
// 4. if the prev's right child is empty, set prev's right child to cur, and set cur to its right child
// 5. if prev's right child is not empty, but equals to cur, reverse visit cur's left child to prev
//       set prev's right child to NULL and set cur to its right child
void BuildPostOrderVector3(TreeNode * const root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    // Create an auxilliary node to help to traverse
    TreeNode *vRoot = new TreeNode(0);
    vRoot->left = root;
    TreeNode *cur = vRoot, *prev = NULL;

    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            cur = cur->right;
        }
        else
        {
            prev = cur->left;

            while (prev->right != NULL && prev->right != cur)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                visitNode(cur->left, prev, v);
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }

    vRoot->left = NULL;
    delete vRoot;
    vRoot = NULL;
}

// Deserialization
void ReBuildTreeFromOrderLevel(TreeNode **root, const vector<string> &s)
{
    int size = s.size();
    
    if (size == 0 || s[0] == "#")
    {
        *root = NULL;
    }

    queue<TreeNode *> q;
    *root = new TreeNode(atoi(s[0].c_str()));
    q.push(*root);
    cout << "Creating node : " << (*root)->val << endl;

    for (int i = 1; i < size; )
    {
        TreeNode *node = NULL;
        bool left = true;

        while (!q.empty() && i < size)
        {
            if (left)
            {
                node = q.front();
                q.pop();
            }

            if (s[i] == "#")
            {
                i++;

                if (left)
                {
                    cout << "left leaf child of " << node->val << " is empty leaf #!" << endl;
                }
                else
                {
                    cout << "right leaf child of " << node->val << " is empty leaf #!" << endl;
                }
            }
            else
            {
                TreeNode *tmp = new TreeNode(atoi(s[i].c_str()));
                q.push(tmp);

                if (left)
                {
                    node->left = tmp;
                    cout << "Creating node : " << tmp->val << " for as left child of " << node->val << endl;
                }
                else
                {
                    node->right = tmp;
                    cout << "Creating node : " << tmp->val << " for as right child of " << node->val << endl;
                }

                i++;
            }

            left = !left;
        }
    }
}


void BuildOrderLevelVector(TreeNode * const root, vector<string> &v)
{
    if (root == NULL)
    {
        v.push_back("#");
        return;
    }

    queue<TreeNode *> q;
    v.push_back(std::to_string(root->val));
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        if (node->left != NULL)
        {
            TreeNode *left = node->left;
            v.push_back(std::to_string(left->val));
            q.push(left);
        }
        else
        {
            v.push_back("#");
        }

        if (node->right != NULL)
        {
            TreeNode *right = node->right;
            v.push_back(std::to_string(right->val));
            q.push(right);
        }
        else
        {
            v.push_back("#");
        }
    }
}

// using low, hight range to check BST
// caller should pass INT_MIN and INT_MAX as low, hight
bool isBST(TreeNode *root, int low, int high)
{
    if (root == NULL)
    {
        return true;
    }

    if (low < root->val && root->val < high)
    {
        return isBST(root->left, low, root->val) && isBST(root->right, root->val, high);
    }
    else
    {
        return false;
    }
}

// using prev value and inorder traverse to check BST
// caller should pass INT_MIN as prev
bool isBST2(TreeNode *root, int &prev)
{
    if (root == NULL)
    {
        return true;
    }

    if (isBST2(root->left, prev))
    {
        if (root->val > prev)
        {
            prev = root->val;
            return isBST2(root->right, prev);
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

#ifndef EXPORTED
int main()
{
    /*
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
    //    cout << "The biggest node is " << biggest->val << endl;
    //}

    //TreeNode *smallest = FindSmallestInTree(root);

    //if (smallest != NULL)
    //{
    //    cout << "The smallest node is " << smallest->val << endl;
    //}

    DestroyTree(root);

    //TreeToLinkList(root);
    //TreeToLinkListWithRecursion(root);

    int szPreOrder[TREELEN] = {5, 4, 11, 7, 2, 8, 13, 4, 1};
    int szInOrder[TREELEN] = {7, 11, 2, 4, 5, 13, 8, 4, 1};
    int szPostOrder[TREELEN] = {7, 2, 11, 4, 13, 1, 4, 8, 5};

    const int TREELEN = 7;
    int szPreOrder[TREELEN] = {1, 2, 3, 4, 5, 6, 7};
    int szInOrder[TREELEN] = {3, 2, 4, 1, 6, 5, 7};
    int szPostOrder[TREELEN] = {3, 4, 2, 6, 7, 5, 1};
    */

    TreeNode *root = NULL;
    //ReBuildTreeFromPreIn(szPreOrder, szInOrder, TREELEN, root);
    //ReBuildTreeFromPrePost2(szPreOrder, szPostOrder, TREELEN, root);
    //ReBuildTreeFromInPost2(szInOrder, szPostOrder, TREELEN, root);

    //string leaf[11] = {"1", "2", "2", "3", "#", "#", "3", "4", "#", "#", "4"};

    //vector<int> v;
    //vector<string> v(leaf, leaf + 11);
    //ReBuildTreeFromOrderLevel(&root, v);
    
    //string  bst[7] = {"30", "20", "40", "10", "25", "35", "50"};
    //vector<string> bstv(bst, bst + 7);

    //ReBuildTreeFromOrderLevel(&root, bstv);
    //cout << "Is this a BST? " << isBST(root, INT_MIN, INT_MAX) << endl;

    //vector<string> s;
    //BuildOrderLevelVector(root, s);
    //printVector(s);

    //BuildPreOrderVector3(root, v);
    //BuildInOrderVector3(root, v);
    //BuildPostOrderVector3(root, v);
    //printVector(v);

    string  s[13] = {"30", "10", "50", "#", "#", "#", "20", "45", "#", "#", "35", "#", "#"};
    vector<string> v(s, s + 13);
    int index = 0;
    ReBuildTreeFromPreOrder(root, v, index);

    vector<int> v2;
    BuildPreOrderVector(root, v2);
    printVector(v2);

    CleanUp2(root);
    return 0;
}
#endif
