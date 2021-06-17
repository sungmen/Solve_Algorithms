# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.res = 0
    
    def dfs(self, root: TreeNode, resVal: int):
        if resVal <= root.val:
            resVal = root.val
            self.res += 1
            
        if root.left != None:
            self.dfs(root.left, resVal)
        
        if root.right != None:
            self.dfs(root.right, resVal)
            
    
    def goodNodes(self, root: TreeNode) -> int:
        self.dfs(root, root.val)
        
        return self.res