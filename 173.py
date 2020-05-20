class BSTIterator(object):
    
    def update(self):
        while(self.st[-1].left):
            self.st.append(self.st[-1].left)
        return
    
    def __init__(self, root):
        self.st = []
        if (root is not None):
            self.st.append(root) 
            self.update()
        
    def next(self):
        node = self.st[-1]
        self.st.pop()
        if(node.right):
            self.st.append(node.right)
            self.update()
        return node.val
        

    def hasNext(self):
        return len(self.st) !=0 
