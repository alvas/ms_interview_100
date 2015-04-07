#include <iostream>
#include <queue>

#include "Tree.h"

using namespace std;

const int TREELEN = 7;

class Solution {
public:
    int maxDepth(TreeNode *root) {
        int depth = 0;

        if (root != NULL)
        {
            queue<TreeNode *> q;
            q.push(root);

            while(!q.empty())
            {
                queue<TreeNode *> tmp;
                tmp.swap(q);
                depth++;

                while (!tmp.empty())
                {
                    TreeNode *node = tmp.front();
                    tmp.pop();

                    if (node->left != NULL)
                    {
                        q.push(node->left);
                    }

                    if (node->right != NULL)
                    {
                        q.push(node->right);
                    }
                }
            }
        }

        return depth;
    }
};

int main()
{
    Solution sln;
    TreeNode *root = NULL;

    int szInOrder[TREELEN] = {3, 2, 4, 1, 6, 5, 7};
    int szPostOrder[TREELEN] = {3, 4, 2, 6, 7, 5, 1};

    ReBuildTreeFromInPost2(szInOrder, szPostOrder, TREELEN, root);
    cout << sln.maxDepth(root) << endl;
    CleanUp(root);
    return 0;
}
