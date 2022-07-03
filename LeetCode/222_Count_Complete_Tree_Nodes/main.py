# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.cnt = 0
        
    def dfs(self, root: TreeNode) -> None:
        if root == None: return
        
        self.cnt += 1
        
        if root.left != None:
            self.dfs(root.left)
        
        if root.right != None:
            self.dfs(root.right)
        
    def countNodes(self, root: TreeNode) -> int:
        self.dfs(root)
        return self.cnt
        