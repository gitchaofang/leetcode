class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        std::vector<std::pair<int,int>> dp(n,{0,0});
        int res = 0;
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(rating[i] > rating[j]){ 
                    ++dp[i].first;
                    res += dp[j].first;
                }
                else if(rating[i] < rating[j]){
                    ++dp[i].second;
                    res += dp[j].second;
                }
            }
        }
        return res; 
    }
};
