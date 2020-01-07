class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k >= n){
            int res = 0;
            for(int i=1; i<n; ++i) res += std::max(0,prices[i] - prices[i-1]);
            return res;
        }
        std::vector<std::vector<int>> l(n,std::vector<int>(k+1,0));
        std::vector<std::vector<int>> g(n,std::vector<int>(k+1,0));
        for(int i=1; i<n; ++i){
            int diff = prices[i] - prices[i-1];
            for(int j=1; j<=k; ++j){
                l[i][j] = std::max(l[i-1][j] + diff, g[i-1][j-1] + std::max(diff,0));
                g[i][j] = std::max(g[i-1][j],l[i][j]);
            }
        }
        return g[n-1][k];
    }
};
