from sets import Set
class Solution(object):
    def dfs(self,s,l,check):
        if(s==""):
            return True;
        for ss in l:
            if(ss == s):
                return True
            if(len(ss) > len(s) or s[0:len(ss)] != ss): 
                continue;
            ts = s[len(ss)-len(s):]
            if(ts in check):
                continue
            found = self.dfs(ts,l,check)
            if(found == True):
                return True
        check.add(s)
        return False
    def wordBreak(self, s, wordDict):
        l = Set([])
        check = Set([])
        for ele in wordDict:
            l.add(ele)
        return self.dfs(s,l,check)
