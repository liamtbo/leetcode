/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // empty tree case
        if (!root) return false;

        // leaf base cases
        if (root->left == nullptr && root->right == nullptr && root->val == targetSum) return true;
        if (root->left == nullptr && root->right == nullptr && root->val != targetSum) return false;

        // recursive case
        bool in_left_path = hasPathSum(root->left, targetSum - root->val);
        bool in_right_path = hasPathSum(root->right, targetSum - root->val);

        return in_left_path || in_right_path;
    }
};