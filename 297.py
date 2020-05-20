class Codec:
    def __init__(self):
        self.cache = []
        self.i = 0;
        
    def serialize(self, root):
        if(not root):
            return "#"
        res = str(root.val)
        res += " " + self.serialize(root.left)
        res += " " + self.serialize(root.right)
        return res
        
    def des(self):
        val = self.cache[self.i]
        self.i += 1
        if(val == "#"):
            return None
        node = TreeNode(int(val))
        node.left = self.des();
        node.right = self.des();
        return node
    
    def deserialize(self, data):
        self.cache = data.split(" ");
        return self.des();
