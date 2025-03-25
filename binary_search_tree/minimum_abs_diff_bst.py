# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def get_in_order(self, root: Optional[TreeNode]):
        result = []
        def dfs(node):
            if not node:
                return
            dfs(node.left)
            result.append(node.val)
            dfs(node.right)
        dfs(root)
        return result


    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        """
        sol2
        do in order traversal and create in-order arry
        loop over in-order array
            for every value, calc diff of left and right in array
        return smallest
        """
        in_order = self.get_in_order(root)

        current_min = float('inf')
        for i in range(len(in_order) - 1):
            diff = abs(in_order[i] - in_order[i+1])
            if diff < current_min:
                current_min = diff
        return current_min
    
"""
better solution

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traverse(self, node: TreeNode) -> None:
        if not node: return
        self.traverse(node.left)
        self.nums.append(node.val)
        self.traverse(node.right)

    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        self.nums = []
        self.traverse(root)
        return min([self.nums[i+1]-self.nums[i] for i in range(len(self.nums)-1)])
"""