#include <iostream>
#include <string>
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
    int pathSum(TreeNode* root, int sum) {
    }
};

int main() {
    Solution sln;
    int sum = 8;
    TreeNode* root = nullptr; 
    vector<string> v = {"10", "5", "-3", "3", "2", "#", "11", "3", "-2", "#", "1", "#", "#"};
    ReBuildTreeFromOrderLevel(v, root);
    cout << sln.pathSum(root, sum) << endl;
    return 0;
}
