import sys
class Solution(object):
    def __init__(self):
        self.res = -sys.maxint 
    def dfs(self,root):
        if(not root): 
            return 0;
        left = max(0,self.dfs(root.left))
        right = max(0,self.dfs(root.right))
        self.res = max(self.res,root.val + left + right)
        return root.val + max(left,right)
    
    def maxPathSum(self, root):
        self.dfs(root)
        return self.res
        
        
