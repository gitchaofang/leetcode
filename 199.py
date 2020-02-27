class Solution(object):
    def rightSideView(self, root):
        if(not root): 
            return[]
        q = [root]
        res = []
        while(len(q)!=0):
            n = len(q)
            for i in range(0,n):
                node = q.pop(0)
                if(i == n-1):
                    res.append(node.val)
                if(node.left):
                    q.append(node.left)
                if(node.right):
                    q.append(node.right)
        return res
            
        
