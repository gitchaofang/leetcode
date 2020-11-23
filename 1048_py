class Solution(object):
    def longestStrChain(self, words):
        words.sort(key = len)
        print(words)
        dic = {}
        res = 0
        for s in words:
            cnt = 1
            for i in range(0,len(s)):
                ss = s[0:i] + s[i+1:]
                if ss not in dic:
                    continue
                cnt = max(cnt,dic[ss] + 1)
            dic[s] = cnt
            res = max(cnt,res)
        return res
        
