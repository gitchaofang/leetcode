class Solution(object):
    def __init__(self):
        self.i = 0
    
    def decodeString(self, s):
        res = ""
        while(self.i<len(s) and s[self.i] != ']'):
            if(s[self.i] <= '9' and s[self.i] >='0'):
                cnt = 0
                while(s[self.i] !='['):
                    cnt = cnt*10 + int(s[self.i])
                    self.i += 1
                self.i += 1
                ts = self.decodeString(s)
                for k in range(0,cnt):
                    res += ts
                self.i += 1
            else:
                res += s[self.i]
                self.i += 1
        return res          
    
