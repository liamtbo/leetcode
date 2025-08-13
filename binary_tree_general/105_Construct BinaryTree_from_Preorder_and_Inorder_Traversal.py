
"""
Time complexity:
    recursive step for each node -> O(n) time
        using deque so popping first element of preorder is O(1)
        getting index of inorder, worst case go through whole list so O(n)?
    O(n^2)
Space complexity:
    best case scenerio: balanced tree (height of logn)
        for each recursive call on the stack (logn)
            create 2 new sliced array (n)
        space complexity: O(log n)
    worst case scenerio: skewed tree (heigh of n)
        for each recursive call (n)
            create 2 new slices arrays (n)
        space comlexity: O(log n)
"""

from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        preorder = deque(preorder) # doubly ended queue is more efficient when popping from beginning

        def build(preorder, inorder):
            """ 'if inorder' and not 'if preorder' bc preorder pops from the left and on each recursive call, 
            contains values not found in that specific nodes subtree. Inorder, on each recursion call, only 
            contains values that are within that nodes subtree"""
            if inorder:
                # preorder starts with tree root node, thus we can infer we start the tree by doing this
                node_val = preorder.popleft() 
                node_val_idx = inorder.index(node_val) # can do bc all node vals are unique
                # building current tree node
                node = TreeNode(node_val)
                # inorder[:node_val_idx] will contain values only found in left part of current nodes subtree
                node.left = build(preorder, inorder[:node_val_idx])
                # similary with the right side
                node.right = build(preorder, inorder[node_val_idx + 1:])
                return node

        return build(preorder, inorder)
    
def main():
    print(Solution().buildTree([3,9,20,15,7], [9,3,15,20,7]))

main()


"""
C++
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) {}
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        std::deque<int> preorder_deque(preorder.begin(), preorder.end());

        return build(preorder_deque, inorder);

    }
private: // private bc it's a helper function that won't be accessed outsdide of public functions within this class
    TreeNode *build(deque<int>& preorder, vector<int>& inorder) {
        if (!inorder.empty()) {
            int val = preorder.front();
            preorder.pop_front();
            auto idx_it = find(inorder.begin(), inorder.end(), val);
            int idx = idx_it - inorder.begin();
            TreeNode *node = new TreeNode(val);
            vector<int> left_inorder(inorder.begin(), inorder.begin() + idx);
            vector<int> right_inorder(inorder.begin() + idx + 1, inorder.end());
            node->left = build(preorder, left_inorder);
            node->right = build(preorder, right_inorder);
            return node;
        }
        return nullptr;
    }
};


"""