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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        /*
        iterate over tree p
        check if any branches don't exist in q
        if it does exist check value
        */
        if (!p && !q) return true;
        if (!p && q) return false;
        if (p && !q) return false;

        if (p->val != q->val) return false;
        bool left = 1; 
        bool right = 1;
        left = isSameTree(p->left, q->left);
        right = isSameTree(p->right, q->right);
        return left && right;
    }
};