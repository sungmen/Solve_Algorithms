# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
sys.setrecursionlimit(10**5)
class Solution:
    def invert(self, root:TreeNode) -> None:
        if root != None:
            l = root.left
            r = root.right

            root.left = r
            root.right = l

            self.invert(root.left)
            self.invert(root.right)
        
    def invertTree(self, root: TreeNode) -> TreeNode:
        self.invert(root)
        return root