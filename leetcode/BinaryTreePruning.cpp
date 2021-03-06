/*
 * BinaryTreePruning.cpp
 * Copyright (C) 2018 qingyun <qingyun.oracle@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>

#include "Tree.h"
#include "UnitTest.h"

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
    TreeNode* pruneTree(TreeNode* root) {
        if (isEmpty(root)) {
            root = nullptr;
        }

        return root;
    }

    bool isEmpty(TreeNode *root) {
        if (!root) {
            return true;
        }

        bool leftNull = isEmpty(root->left);

        if (leftNull) {
            root->left = nullptr;
        }

        bool rightNull = isEmpty(root->right);

        if (rightNull) {
            root->right = nullptr;
        }

        // be careful about this checking condition
        return root->val == 0 && leftNull && rightNull;
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
        vector<string> s = {"1", "#", "0", "0", "1"};
        ReBuildTreeFromOrderLevel<TreeNode>(s, root);
        root = sln.pruneTree(root);
        printTreeLevelOrder(root);
        CleanUp2(root);
        //CHECK_EQUAL(,);
    }

    TEST_FIXTURE(MyFixture, CASE2)
    {
        TreeNode *root = nullptr;
        vector<string> s = {"1", "0", "1", "0", "0", "0", "1"};
        ReBuildTreeFromOrderLevel<TreeNode>(s, root);
        root = sln.pruneTree(root);
        printTreeLevelOrder(root);
        CleanUp2(root);
        //CHECK_EQUAL(,);
    }

    TEST_FIXTURE(MyFixture, CASE3)
    {
        TreeNode *root = nullptr;
        vector<string> s = {"1", "1", "0", "1", "1", "0", "1", "0"};
        ReBuildTreeFromOrderLevel<TreeNode>(s, root);
        root = sln.pruneTree(root);
        printTreeLevelOrder(root);
        CleanUp2(root);
        //CHECK_EQUAL(,);
    }
}

