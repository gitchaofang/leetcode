class Solution(object):
    def __init__(self):
        self.res = 0
    def dc(self, arr,i,j):
        if(i>j):
            return 0
        if(i == j):
            return arr[i]
        targ = i
        for k in range(i,j+1):
            if(arr[k] > arr[targ]):
                targ = k
        left = self.dc(arr,i,targ-1)
        right = self.dc(arr,targ+1,j)
        self.res += arr[targ]*(left + right)
        return arr[targ]
        
    def mctFromLeafValues(self, arr):
        self.dc(arr,0,len(arr)-1)
        return self.res
