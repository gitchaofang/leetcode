class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size(); 
        std::vector<int> dp(n + 1, INT_MIN);
        int sm = 0;
        dp[n] = 0;
        for(int i = n - 1; i >= 0; --i){
            sm += stoneValue[i];
            for(int j = 1; j <= 3; ++j){
                if(i + j > n) break;
                dp[i] = std::max(dp[i], sm - dp[i + j]); 
            }
        }
        if(dp[0] * 2 == sm) return "Tie";
        if(dp[0] * 2 > sm) return "Alice";
        return "Bob";
    }
};
