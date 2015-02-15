#include <iostream>
#include <queue>
#include <stack>

using namespace std;

const int TREELEN = 7;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {

        if (root == NULL)
        {
            cout << "root == NULL" << endl;
            return false;
        }
        else if (root->left == NULL && root->right == NULL)
        {
            sum -= root->val;

            if (sum == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        sum -= root->val;
        bool hasSum = false;
        
        if (root->left != NULL)
        {
            hasSum = hasPathSum(root->left, sum);
        }

        if (root->right != NULL && !hasSum)
        {
            hasSum = hasPathSum(root->right, sum);
        }

        return hasSum;
    }
};

void ReBuildFromPrePost(int *preOrder, int *postOrder, int nTreeLen, TreeNode *&root)
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
    ReBuildFromPrePost(preOrder + 1, postOrder, i, root->left);
    ReBuildFromPrePost(preOrder + i + 1, postOrder + i, nTreeLen - i - 1, root->right);
}

void ReBuildFromInPost(int *inOrder, int *postOrder, int nTreeLen, TreeNode *&root)
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
    ReBuildFromInPost(inOrder, postOrder, i, root->left);
    ReBuildFromInPost(inOrder + i + 1, postOrder + i, nTreeLen - i - 1, root->right);
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

// Using reference to pointer
void ReBuildFromPreIn(int *preOrder, int *inOrder, int nTreeLen, TreeNode *&root)
{
    if (preOrder == NULL || inOrder == NULL || nTreeLen <= 0)
    {
        root = NULL;
        return;
    }

    int tmp = preOrder[0];
    int i = 0;

    cout << "Node: " << tmp << endl;
    
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
    ReBuildFromPreIn(preOrder + 1, inOrder, i - 1, root->left);
    ReBuildFromPreIn(preOrder + i, inOrder + i, nTreeLen - i, root->right);
}

// Construct tree from preOrder and InOrder using stack
void ReBuildFromPreIn2(int *preOrder, int *inOrder, int nTreeLen, TreeNode *&root)
{
    if (preOrder == NULL || inOrder == NULL || nTreeLen <= 0)
    {
        root = NULL;
        return;
    }

    stack<TreeNode *> s;
    int pdx = 0, idx = 0;
    root = new TreeNode(preOrder[pdx++]);
    TreeNode *p = root;

    // Indicator whether to add the node as a right child
    bool addRightChild = false;

    while (pdx < nTreeLen)
    {
        if (!s.empty() && s.top()->val == inOrder[idx])
        {
            p = s.top();
            s.pop();
            addRightChild = true;
            idx++;
        }
        else
        {
            if (addRightChild)
            {
                p->left = new TreeNode(preOrder[pdx++]);
                p = p->left;
                s.push(p);
            }
            else
            {
                addRightChild = false;
                p->right = new TreeNode(preOrder[pdx++]);
                p = p->right;
                s.push(p);
            }
        }
    }
}

int main()
{
    /*
    int szPreOrder[TREELEN] = {5, 4, 11, 7, 2, 8, 13, 4, 1};
    int szInOrder[TREELEN] = {7, 11, 2, 4, 5, 13, 8, 4, 1};
    int szPostOrder[TREELEN] = {7, 2, 11, 4, 13, 1, 4, 8, 5};

    int szPreOrder[TREELEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int szInOrder[TREELEN] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    int szPreOrder[TREELEN] = {4, 4, 4, 4, 4, 4, 4, 4, 4};
    int szInOrder[TREELEN] = {4, 4, 4, 4, 4, 4, 4, 4, 4};

    int szPreOrder[TREELEN] = {1, 2, 3};
    int szInOrder[TREELEN] = {2, 1, 3};
    */

    int szPreOrder[TREELEN] = {1, 2, 3, 4, 5, 6, 7};
    int szInOrder[TREELEN] = {3, 2, 4, 1, 6, 5, 7};

    TreeNode *root = NULL;
    ReBuildFromPreIn2(szPreOrder, szInOrder, TREELEN, root);
    //ReBuildFromPrePost(szPreOrder, szPostOrder, TREELEN, root);
    //ReBuildFromInPost(szInOrder, szPostOrder, TREELEN, root);

    cout << "Please enter the sum: ";
    int num = 0;
    cin >> num;

    Solution sln;
    cout << sln.hasPathSum(root, num) << endl;
    CleanUp2(root);
    return 0;
}

