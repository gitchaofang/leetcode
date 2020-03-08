class Solution(object):
    def maxProfit(self, k, prices):
        n = len(prices)
        if(k >= n):
            res = 0;
            for i in range(1,n):
                res += max(prices[i] - prices[i-1],0)
            return res
        
        l = [[0 for i in range(0,k+1)] for j in range(0,n)]
        g = [[0 for i in range(0,k+1)] for j in range(0,n)]
        for i in range(1,n):
            diff = prices[i] - prices[i-1]
            for j in range(1,k+1):
                l[i][j] = max(l[i-1][j] + diff, g[i-1][j-1] + max(0,diff));
                g[i][j] = max(l[i][j],g[i-1][j]);
        return g[-1][-1]
