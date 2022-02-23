/*
 * MorrisTraversal.cpp
 * Copyright (C) 2022 qingyun <qingyun.oracle@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int x): val(x) {}
};

void inorderMorrisTraversal(TreeNode* root) {
    TreeNode *cur = root, *prev = nullptr;

    while (cur) {
        if (cur->left == nullptr) {
            cout << cur->val << " ";
            cur = cur->right;
        }
        else {
            prev = cur->left;

            while (prev->right && prev->right != cur) {
                prev = prev->right;
            }

            if (prev->right == nullptr) {
                prev->right = cur;
                cur = cur->left;
            }
            else {
                prev->right = nullptr;
                cout << cur->val << " ";
                cur = cur->right;
            }
        }
    }
}

int main() {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    node4->left = node2;
    node4->right = node6;
    node2->left = node1;
    node2->right = node3;
    node6->left = node5;
    node6->right = node7;
    inorderMorrisTraversal(node4);
    return 0;
}

