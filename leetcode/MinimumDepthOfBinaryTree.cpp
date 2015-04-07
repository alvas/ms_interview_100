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
    cout << sln.minDepth(root) << endl;
    CleanUp(root);
    return 0;
}

