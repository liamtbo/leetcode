

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
/*
time complexity 
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        // base cases
        if (!root->left && !root->right) return 1;
        // recursive case
        return max(1+maxDepth(root->left), 1+maxDepth(root->right));
    }
};