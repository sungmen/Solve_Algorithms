# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.depth = 1e9
        
    def dfs(self, root: TreeNode, cnt: int):
        if root.left == None and root.right == None:
            if self.depth > cnt:
                self.depth = cnt
            return
        
        if root.left != None:
            self.dfs(root.left, cnt + 1)
        
        if root.right != None:
            self.dfs(root.right, cnt + 1)
        
    def minDepth(self, root: TreeNode) -> int:
        if root == None:
            return 0
        self.dfs(root, 1)
        
        return self.depth
        