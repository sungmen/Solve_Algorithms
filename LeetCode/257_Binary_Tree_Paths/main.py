# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.res = []
    
    def dfs(self, root: TreeNode, write: str) -> None:
        if root.left != None:
            tmp = write + ('->' + str(root.left.val))
            self.dfs(root.left, tmp)
        
        if root.right != None:
            tmp = write + ('->' + str(root.right.val))
            self.dfs(root.right, tmp)
        
        if root.left == None and root.right == None:
            self.res.append(write)
    
    
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        w = str(root.val)
        self.dfs(root, w)
        return self.res