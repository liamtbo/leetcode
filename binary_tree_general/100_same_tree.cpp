
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {} 
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
time complexity: O(n)
    - every node in the tree is hit once 
memory complexity: O(h), where h is height tree
    worse case: O(n)
        - skewed tree
    best case: O(logn)
        - balanced tree
*/

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p and !q) {return false;}
        if (!p and q) {return false;}
        if (!p and !q) {return true;}
        if (p->val != q->val) {return false;}
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
};