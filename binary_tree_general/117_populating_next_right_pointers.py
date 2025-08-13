"""
space complexity:
    every node is only stored once so O(n)

time complexity
    every node is visited a single time O(n)

""" 



"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""



class Solution:
    def connect(self, root: 'Node') -> 'Node':
        def bfs(next_layer: list[Node]):
            if next_layer: # base case - next_layer will be empty at bottom of tree
                curr_layer = next_layer
                next_layer = []
                for node in curr_layer:
                    if node.left:
                        next_layer.append(node.left)
                    if node.right:
                        next_layer.append(node.right)
                for node_idx in range(len(next_layer) - 1):
                    next_layer[node_idx].next = next_layer[node_idx + 1]
                if next_layer:
                    next_layer[len(next_layer) - 1].next = None
                bfs(next_layer)
        if not root: return
        bfs([root])
        return root
        