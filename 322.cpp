class Solution {
public:
    int coinChange(vector<int>& coins, int amount) { 
        std::vector<int> dp(amount+1,amount + 1);
        dp[0] = 0;
        std::set<int> st(coins.begin(),coins.end());
        for(int i=1; i<=amount; ++i){
            for(auto it = st.begin(); it != st.end(); ++it){
                int targ = i - *it;
                if(targ < 0) break;
                dp[i] = std::min(dp[i], dp[targ]+1);
            }
            
        }
        return dp[amount] == amount + 1 ? -1: dp[amount];
    }
};
