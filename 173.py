class BSTIterator(object):
    
    def update(self,st):
        while(self.st[-1].left):
            self.st.append(self.st[-1].left)
        return
    
    def __init__(self, root):
        self.st = []
        if (root is not None):
            self.st.append(root) 
            self.update(self.st)
        
    def next(self):
        node = self.st[-1]
        self.st.pop()
        if(node.right):
            self.st.append(node.right)
            self.update(self.st)
        return node.val
        

    def hasNext(self):
        return len(self.st) !=0 
