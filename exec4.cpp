#include <iostream>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

static TreeNode *root = NULL;

void printPath(int path[], int top)
{
    cout << "The path is :" << endl;

    for (int i = 0; i < top; ++i)
    {
        cout << path[i] << "\t";
    }

    cout << endl;
}

void helper(TreeNode *root, int sum, int path[], int top)
{
    path[top++] = root->data;
    sum -= root->data;
    
    if (root->left == NULL && root->right == NULL)
    {
        if (sum == 0)
        {
            printPath(path, top);
        }
    }
    else
    {
        if (root->left != NULL)
        {
            helper(root->left, sum, path, top);
        }
        
        if (root->right != NULL)
        {
            helper(root->right, sum, path, top);
        }
    }

    top--;
    sum += root->data;
}

void printPaths(TreeNode *root, int sum)
{
    int path[100];
    helper(root, sum, path, 0);
}

int main()
{
//    printPaths(root, 22);
    return 0;
}

