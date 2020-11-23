class Solution(object):
    def minDominoRotations(self, A, B):
        top = [0]*6
        bot = [0]*6
        both = [0]*6
        ele = [-1]*6
        for i in range(0,len(A)):
            ele[A[i]-1] = 1
            ele[A[i]-1] = 1
            if(A[i] == B[i]):
                both[A[i]-1] += 1
            else:
                top[A[i]-1] += 1
                bot[B[i]-1] += 1
        res = len(A) + 1
        for i in range(0,len(ele)):
            if(ele[i] == -1):
                continue
            if((top[i] + bot[i] + both[i]) == len(A)):
                res = min(res,min(top[i],bot[i]))
        if(res == len(A)+1): 
            return -1
        return res
