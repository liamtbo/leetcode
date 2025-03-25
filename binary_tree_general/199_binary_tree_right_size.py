# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root: return []

        right_view = []
        parents = []
        children = [root]

        while children:
            right_view.append(children[-1].val)
            parents = children
            children = []
            for parent in parents:
                if parent.left: children.append(parent.left)
                if parent.right: children.append(parent.right)
        return right_view
