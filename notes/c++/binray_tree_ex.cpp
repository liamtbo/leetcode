
#include <vector>
#include <iostream>
using namespace std;

/*
Run with:
    g++ filepath -o main; ./main
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

void in_order(TreeNode *node) {
    if (not node) {return;}

    cout << node->val << endl;
    in_order(node->left);
    if (node->left) {
        cout << "Delete Node:" << node->left->val << endl;
        delete(node->left);}
    in_order(node->right);
    if (node->right) {
        cout << "Delete Node:" << node->right->val << endl;
        delete(node->right);}
}

int main() {
    TreeNode *root = new TreeNode(5);
    TreeNode *left = new TreeNode(4);
    TreeNode *right = new TreeNode(6);
    TreeNode *left_left = new TreeNode(3);

    root->left = left;
    root->right = right;
    left->left = left_left;

    in_order(root);

    if (root) {
        cout << "Delete Node:" << root->val << endl;
        delete(root);
    }

    return 0;
}