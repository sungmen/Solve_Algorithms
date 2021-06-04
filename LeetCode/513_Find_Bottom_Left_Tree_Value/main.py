# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.res = 0
        self.deep = 0
    
    def dfs(self, root: TreeNode, floor: int) -> None:
        if root.left != None:
            self.dfs(root.left, floor+1)
            
        if root.left == None and root.right == None:
            if self.deep < floor:
                self.deep = floor
                self.res = root.val
            return
            
        if root.right != None:
            self.dfs(root.right, floor+1)
        
    def findBottomLeftValue(self, root: TreeNode) -> int:
        self.res = root.val
        self.dfs(root, 0)
        return self.res