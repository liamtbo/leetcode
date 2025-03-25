# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
        
    def isMirror(self, left: TreeNode, right: TreeNode):
        # base case: neither exist
        if left is None and right is None: return True
        # check if mirrored node exists or not
        if (left.left is None) ^ (right.right is None): return False
        if (left.right is None) ^ (right.left is None): return False
        # check if mirror value is the same
        if left.left is not None and right.right is not None:
            if left.left.val != right.right.val: return False
        if left.right is not None and right.left is not None:
            if left.right.val != right.left.val: return False
        
        return self.isMirror(left.left, right.right) and self.isMirror(left.right, right.left)

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        """
        breadth first search, place -101 in spot of empty leaf
        check reflection
        """
        if not root: return False
        if (root.left is None) ^ (root.right is None): return False
        if root.left is None and root.right is None: return True
        if root.left.val != root.right.val: return False
    
        return self.isMirror(root.left, root.right)


# better solution found
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        
        def is_mirror(n1, n2): # n1:left, n2:right
            if not n1 and not n2:
                return True
            
            if not n1 or not n2:
                return False
            
            return n1.val == n2.val and is_mirror(n1.left, n2.right) and is_mirror(n1.right, n2.left)
        
        return is_mirror(root.left, root.right)