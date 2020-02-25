class Solution(object):
    def countAndSay(self, n):
        res = "1"
        for step in range(1,n):
            s = "";
            i=0
            while(i<len(res)):
                print(i)
                j = i
                while(j < len(res) and res[j] == res[i]):
                    j+=1
                s = s+ (str(j-i) + res[i])
                i = j
            res = s
        return res
