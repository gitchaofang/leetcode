class Solution(object):
    def are(self,v):
        n = len(v)
        res = 0
        for i in range(0,n):
            if(i+1<n and v[i] <= v[i+1]):
                continue
            h = v[i]
            for j in range(i,-1, -1):
                h = min(h,v[j])
                res = max(h*(i-j+1),res)
        return res
                
    def maximalRectangle(self, matrix):
        row = len(matrix)
        if(row == 0):
            return 0;
        col = len(matrix[0])
        res = 0
        v = [0]*col
        for i in range(0,row):
            for j in range(0,col):
                if(matrix[i][j] == '0'):
                    v[j] = 0
                else:
                    v[j] += 1
            d = self.are(v)
            res = max(res,d)
        return res
