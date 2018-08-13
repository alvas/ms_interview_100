/*
 * LeafSimilarTrees.cpp
 * Copyright (C) 2018 qingyun <qingyun.oracle@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <queue>

#include "UnitTest.h"
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        queue<int> leafs1;
        traverse(root1, leafs1);
        bool similar =  check(root2, leafs1);
        return similar && leafs1.empty();
    }

    bool leafSimilar1(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs1, leafs2;
        traverse(root1, leafs1);
        traverse(root2, leafs2);
        return leafs1 == leafs2;
    }

    void traverse(TreeNode *root, queue<int> &leafs) {
        if (!root) {
            return;
        }
        else if (!root->left && !root->right) {
            leafs.push(root->val);
            return;
        }

        if (root->left) {
            traverse(root->left, leafs);
        }

        if (root->right) {
            traverse(root->right, leafs);
        }
    }

    bool check(TreeNode *root, queue<int> &leafs) {
        if (!root) {
            return true;
        }
        else if (!root->left && !root->right) {
            int val = leafs.front();
            leafs.pop();
            return val == root->val;
        }

        // be careful about the initialization here
        bool checkL = true, checkR = true;

        if (root->left) {
            checkL = check(root->left, leafs);
        }

        if (root->right) {
            checkR = check(root->right, leafs);
        }

        return checkL && checkR;
    }

    void traverse(TreeNode *root, vector<int> &leafs) {
        if (!root) {
            return;
        }
        else if (!root->left && !root->right) {
            leafs.push_back(root->val);
            return;
        }

        if (root->left) {
            traverse(root->left, leafs);
        }

        if (root->right) {
            traverse(root->right, leafs);
        }
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
        TreeNode *root1 = nullptr, *root2 = nullptr;
        vector<string> s1 = {"1", "2", "3", "4", "5", "6", "7", "#", "#", "8", "9"};
        vector<string> s2 = {"1", "2", "3", "5", "9", "6", "7", "4", "8"};
        ReBuildTreeFromOrderLevel<TreeNode>(s1, root1);
        ReBuildTreeFromOrderLevel<TreeNode>(s2, root2);
        bool same = sln.leafSimilar(root1, root2);
        CHECK_EQUAL(true, same);
    }

    TEST_FIXTURE(MyFixture, CASE2)
    {
        TreeNode *root1 = nullptr, *root2 = nullptr;
        vector<string> s1 = {"1", "2", "3", "4", "8", "5", "7", "#", "#", "#", "#", "9", "6"};
        vector<string> s2 = {"1", "2", "3", "4", "8", "9", "5", "#", "#", "#", "#", "#", "#", "6", "7"};
        ReBuildTreeFromOrderLevel<TreeNode>(s1, root1);
        ReBuildTreeFromOrderLevel<TreeNode>(s2, root2);
        bool same = sln.leafSimilar(root1, root2);
        CHECK_EQUAL(true, same);
    }

    TEST_FIXTURE(MyFixture, CASE3)
    {
        TreeNode *root1 = nullptr, *root2 = nullptr;
        vector<string> s1 = {"1", "2", "3", "4", "8", "5", "7", "#", "#", "#", "#", "9", "6"};
        vector<string> s2 = {"1", "2", "3", "4", "8", "9", "5", "#", "#", "#", "#", "6", "7"};
        ReBuildTreeFromOrderLevel<TreeNode>(s1, root1);
        ReBuildTreeFromOrderLevel<TreeNode>(s2, root2);
        bool same = sln.leafSimilar(root1, root2);
        printTreeLevelOrder(root1);
        printTreeLevelOrder(root2);
        CHECK_EQUAL(false, same);
    }

    TEST_FIXTURE(MyFixture, CASE4)
    {
        TreeNode *root1 = nullptr, *root2 = nullptr;
        vector<string> s1 = {"1", "2"};
        vector<string> s2 = {"2", "2"};
        ReBuildTreeFromOrderLevel<TreeNode>(s1, root1);
        ReBuildTreeFromOrderLevel<TreeNode>(s2, root2);
        bool same = sln.leafSimilar(root1, root2);
        CHECK_EQUAL(true, same);
    }
}

