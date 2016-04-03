#include <iostream>
#include <queue>

#include "Tree.h"

using namespace std;

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root)
        {
            return 0;
        }

        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;

        while (!q.empty())
        {
            queue<TreeNode *> p;
            // Be careful, increase depth before we return. Otherwise,
            // the return in the following while loop get wrong result.
            depth++;

            while (!q.empty())
            {
                TreeNode *t = q.front();
                q.pop();

                if (!t->left && !t->right)
                {
                    // Don't use break here, because there are 2 while loop. It doesn't really
                    // terminate and return the right value.
                    return depth;
                }

                if (t->left)
                {
                    p.push(t->left);
                }

                if (t->right)
                {
                    p.push(t->right);
                }
            }

            q.swap(p);
        }

        return depth;
    }

    int minDepth_recursive(TreeNode *root) {
        if (!root)
        {
            return 0;
        }
        else if (!root->left && !root->right)
        {
            return 1;
        }

        // Be careful about the initial value. Because we use min(), we can't set it to 0. Otherwise, 
        // a node without left/right child would return 0 depth. This is wrong.
        int leftD = INT_MAX;

        if (root->left)
        {
            leftD = minDepth(root->left);
        }

        int rightD = INT_MAX;

        if (root->right)
        {
            rightD = minDepth(root->right);
        }

        return min(leftD, rightD) + 1;
    }

    int minDepth3(TreeNode *root) {
        if (root == NULL)
        {
            return 0;
        }

        queue<TreeNode *> q;
        q.push(root);
        TreeNode *rightMost = root;
        int depth = 1;

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left == NULL && node->right == NULL)
            {
                break;
            }

            if (node->left != NULL)
            {
                q.push(node->left);
            }

            if (node->right != NULL)
            {
                q.push(node->right);
            }

            // because we are finding minimum depth, so rightMost can work, because if node has no left and right child,
            // it will break from above.
            if (node == rightMost)
            {
                depth++;
                rightMost = (node->right != NULL) ? node->right : node->left;
            }
        }

        return depth;
    }
    
    int minDepth2(TreeNode *root) {
        if (root == NULL)
        {
            return 0;
        }

        if (root->left == NULL)
        {
            return minDepth(root->right) + 1;
        }

        if (root->right == NULL)
        {
            return minDepth(root->left) + 1;
        }

        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }

    int minDepth1(TreeNode *root) {
        int depth = 0;
        queue<TreeNode *> q;

        // check whether tree is empty
        if (root != NULL)
        {
            q.push(root);
        }

        while (!q.empty())
        {
            queue<TreeNode *> nextLayer;
            TreeNode *node = q.front();
            q.pop();
            depth++;

            // if a node has node child, it is leaf.
            if (node->left == NULL && node->right == NULL)
            {
                return depth;
            }

            while (node->left != NULL || node->right != NULL)
            {
                // if a node on the current layer has child, put child onto next layer queue
                if (node->left != NULL)
                {
                    nextLayer.push(node->left);
                }

                if (node->right != NULL)
                {
                    nextLayer.push(node->right);
                }

                // check whether the queue has become empty
                if (!q.empty())
                {
                    node = q.front();
                    q.pop();

                    // if a node has node child, it is leaf.
                    if (node->left == NULL && node->right == NULL)
                    {
                        return depth;
                    }
                }
                else
                {
                    break;
                }
            }

            // update q with the nodes of next layers of the tree
            q.swap(nextLayer);
        }

        return depth;
    }
};

int main()
{
    Solution sln;
    TreeNode *root = NULL;
    // 1. empty tree
    // 2. tree with 1 node
    // 3. tree with 2 nodes, root and left child; root and right child;
    // 4. tree with 3 nodes, root with left and right children
    // 5. tree with child nodes on one subtree
    // 6. tree with child nodes no both subtrees
    const int TREELEN = 3;
    //int szInOrder[TREELEN] = {3, 2, 4, 1, 6, 5, 7};
    //int szPostOrder[TREELEN] = {3, 4, 2, 6, 7, 5, 1};

    int szInOrder[TREELEN] = {3, 2, 1};
    int szPostOrder[TREELEN] = {3, 2, 1};

    ReBuildTreeFromInPost2(szInOrder, szPostOrder, TREELEN, root);
    std::cout << sln.minDepth(root) << endl;
    std::cout << sln.minDepth_recursive(root) << endl;
    CleanUp(root);
    return 0;
}

