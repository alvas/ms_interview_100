/*
 * MaximumDepthOfNAryTree.cpp
 * Copyright (C) 2018 qingyun <qingyun.oracle@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>

#include "UnitTest.h"
#include "Node.h"

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        int ans = 0, depth = 0;
        traverse(root, ans, depth);
        return ans;
    }

    void traverse(Node* root, int &ans, int depth) {
        if (!root) {
            return;
        }

        depth++;
        ans = max(ans, depth);

        for (auto &c: root->children) {
            traverse(c, ans, depth);
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
        string tree = R"""({v:1, c:[{v:3, c:[{v:5}, {v:6}]}, {v:2}, {v:4}]})""";
        Node *root = constructNaryTree(tree);
        int ans = sln.maxDepth(root);
        CHECK_EQUAL(3, ans);
    }
    
    TEST_FIXTURE(MyFixture, CASE2)
    {
        string tree = R"""({v:1})""";
        Node *root = constructNaryTree(tree);
        int ans = sln.maxDepth(root);
        CHECK_EQUAL(1, ans);
    }

    TEST_FIXTURE(MyFixture, CASE3)
    {
        string tree = R"""({})""";
        Node *root = constructNaryTree(tree);
        int ans = sln.maxDepth(root);
        CHECK_EQUAL(0, ans);
    }

    TEST_FIXTURE(MyFixture, CASE4)
    {
        string tree = R"""({v:1, c: [{v:2}]})""";
        Node *root = constructNaryTree(tree);
        int ans = sln.maxDepth(root);
        CHECK_EQUAL(2, ans);
    }

    TEST_FIXTURE(MyFixture, CASE5)
    {
        string tree = R"""({v:1, c: [{v:2, c: [{v: 3}]}]})""";
        Node *root = constructNaryTree(tree);
        int ans = sln.maxDepth(root);
        CHECK_EQUAL(3, ans);
    }

    TEST_FIXTURE(MyFixture, CASE6)
    {
        string tree = R"""({v:1, c: [{v:2}, {v: 3}]})""";
        Node *root = constructNaryTree(tree);
        int ans = sln.maxDepth(root);
        CHECK_EQUAL(2, ans);
    }
}

