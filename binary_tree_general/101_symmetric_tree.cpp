struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSubTreeSym(TreeNode *left, TreeNode *right) {
        // base case (if both are leaf nodes)
        if (!left->left && !left->right && !right->left && !right->right) {
            if (left->val == right->val) { return true;}
            else {return false;}
        }

        // recursive case
        // each case is for an identical per
        if (left->left && left->right && right->left && right->right) {
            return left->val == right->val && isSubTreeSym(left->left, right->right) 
                && isSubTreeSym(left->right, right->left);
        } else if (left->left && !left->right && !right->left && right->right) {
            return left->val == right->val && isSubTreeSym(left->left, right->right);
        } else if (!left->left && left->right && right->left && !right->right) {
            return left->val == right->val && isSubTreeSym(left->right, right->left);
        } else {
            return false;
        }
    }

    bool isSymmetric(TreeNode* root) {

        if (!root->left && !root->right) { return true; }
        if (root->left && !root->right || !root->left && root->right) { return false; }

        return isSubTreeSym(root->left, root->right);
    }
};