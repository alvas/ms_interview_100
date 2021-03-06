/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <vector>

#include "Tree.h"

using namespace std;

#include "UnitTest.h"

using namespace std;

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root)
            return nullptr;

        return root;
    }
};


SUITE(TEST_CASES)
{
    class MyFixture
    {
    public:
        Solution sln;
    };

    TEST_FIXTURE(MyFixture, CASE1)
    {
        TreeNode *root = nullptr;
        vector<string> s = {"1", "0", "2"};
        ReBuildTreeFromOrderLevel<TreeNode>(s, root);
        int L = 1, R = 2;
        root = sln.trimBST(root, L, R);
        printTreeLevelOrder(root);
        CleanUp2(root);
        //CHECK_EQUAL(,);
    }

    TEST_FIXTURE(MyFixture, CASE2)
    {
        TreeNode *root = nullptr;
        vector<string> s = {"3", "0", "4", "#", "2", "#", "#", "1"};
        ReBuildTreeFromOrderLevel<TreeNode>(s, root);
        int L = 1, R = 3;
        root = sln.trimBST(root, L, R);
        printTreeLevelOrder(root);
        CleanUp2(root);
        //CHECK_EQUAL(,);
    }

    TEST_FIXTURE(MyFixture, CASE3)
    {
        TreeNode *root = nullptr;
        vector<string> s = {"5", "3", "8", "2", "4", "7", "9"};
        ReBuildTreeFromOrderLevel<TreeNode>(s, root);
        int L = 2, R = 8;
        root = sln.trimBST(root, L, R);
        printTreeLevelOrder(root);
        CleanUp2(root);
        //CHECK_EQUAL(,);
    }
}

