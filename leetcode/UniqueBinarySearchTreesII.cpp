#include <iostream>
#include <vector>

#include "Tree.h"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // This problem is really difficult to me. Shame on me. I can't find out the soluton.
    // Need to improve.
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
        {
            return buildSubTree(1, 0);
        }
        else
        {
            return buildSubTree(1, n);
        }
    }

    vector<TreeNode *> &buildSubTree(int s, int e)
    {
        vector<TreeNode *> *subTree = new vector<TreeNode *>();

        if (s > e)
        {
            subTree->push_back(NULL);
            return *subTree;
        }

        for (int i = s; i <= e; ++i)
        {
            vector<TreeNode *> &left = buildSubTree(s, i - 1);
            vector<TreeNode *> &right = buildSubTree(i + 1, e);
            int lsz = left.size(), rsz = right.size();

            for (int j = 0; j < lsz; ++j)
            {
                for (int k = 0; k < rsz; ++k)
                {
                    cout << "creating node " << i << endl;
                    TreeNode *node = new TreeNode(i);
                    node->left = left[j];
                    node->right = right[k];
                    subTree->push_back(node);
                }
            }
        }

        return *subTree;
    }

    //vector<TreeNode*> generateTrees(int n) {
        //vector<TreeNode *> v;
        //vector<TreeNode *> subset;

        //for (int i = 1; i <= n; ++i)
        //{
            //TreeNode *node = new TreeNode(i);
            //subset.push_back(node);
        //}

        //return v;
    //}

    //void buildSubTree(int start, int end, vector<TreeNode *> &subset)
    //{
        //for (int i = 1; i <= n; ++i)
        //{
            //for (int j = 1; j <= n - i; ++j)
            //{
                //for (int k = j; k < i + j; ++k)
                //{
                    //TreeNode *node = new TreeNode(i);
                    //subset.push_back(node);
                //}
            //}
        //}
    //}
};

int main()
{
    Solution sln;
    int n = 0;
    cout << "Please enter n: ";
    cin >> n;
    vector<TreeNode *> v = sln.generateTrees(n);

    for (vector<TreeNode *>::iterator itr = v.begin(); itr != v.end(); ++itr)
    {
        TreeNode *root = *itr;
        printTreeLevelOrder(root);
        //CleanUp2(root);
        cout << endl;
    }

    for (vector<TreeNode *>::iterator itr = v.begin(); itr != v.end(); ++itr)
    {
        CleanUp2(*itr);
    }

    return 0;
}
