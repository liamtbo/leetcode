
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
