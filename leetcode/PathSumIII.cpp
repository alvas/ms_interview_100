#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

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
        if (!root) {
            return 0;
        }

        int res = 0;
        findPath(sum, root, 0, res);
        res += pathSum(root->left, sum) + pathSum(root->right, sum);
        return res;
    }

    void findPath(int sum, TreeNode* root, int preSum, int& res) {
        if (!root) {
            return;
        }

        preSum += root->val;
        res += preSum == sum ? 1 : 0;
        findPath(sum, root->left, preSum, res);
        findPath(sum, root->right, preSum, res);
        return;
    }

    int pathSum2(TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }

        int res = 0;
        solver(root, sum, res);
        return res;
    }

    vector<int> solver(TreeNode* root, int sum, int& count) {
        if (!root) {
            return vector<int>();
        }

        vector<int> left = solver(root->left, sum, count);
        vector<int> right = solver(root->right, sum, count);
        vector<int> res;
        res.push_back(root->val);

        if (root->val == sum) {
            count++;
        }

        for (int i = 0; i < left.size(); ++i) {
            int num = left[i] + root->val;
            
            if (num == sum) {
                count++;
            }

            res.push_back(num);
        }

        for (int i = 0; i < right.size(); ++i) {
            int num = right[i] + root->val;

            if (num == sum) {
                count++;
            }

            res.push_back(num);
        }

        return res;
    }

    int pathSum1(TreeNode* root, int sum) {
        int res = 0;
        
        if (!root) {
            return res;
        }

        unordered_set<TreeNode*> s;
        dfs(root, sum, sum - root->val, res, s);
        return res;
    }

    void dfs(TreeNode* root, const int origin, int sum, int &res, unordered_set<TreeNode*>& s) {
        if (!root) {
            return;
        }

        if (!sum) {
            res++;
        }

        if (root->left) {
            dfs(root->left, origin, sum - root->left->val, res, s);

            // origin - root->left->val could be encounted twice
            // for example vector<string> v = {"1", "#", "2", "#", "3", "#", "4", "#", "5"};
            if (s.find(root->left) == s.end()) {
                dfs(root->left, origin, origin - root->left->val, res, s);
                s.insert(root->left);
            }
        }

        if (root->right) {
            dfs(root->right, origin, sum - root->right->val, res, s);

            if (s.find(root->right) == s.end()) {
                dfs(root->right, origin, origin - root->right->val, res, s);
                s.insert(root->right);
            }
        }
    }
};

int main() {
    Solution sln;
    int sum = 8;
    TreeNode* root = nullptr; 
    //vector<string> v = {"1"};
    //vector<string> v = {"1", "2"};
    vector<string> v = {"10", "5", "-3", "3", "2", "#", "11", "3", "-2", "#", "1", "#", "#"};
    //vector<string> v = {"1", "#", "2", "#", "3", "#", "4", "#", "5"};
    ReBuildTreeFromOrderLevel(v, root);
    cout << sln.pathSum(root, sum) << endl;
    CleanUp2<TreeNode>(root);
    return 0;
}
