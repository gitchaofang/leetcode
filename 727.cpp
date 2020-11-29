class Solution {
public:
    string minWindow(string S, string T) {
        int sn = S.size();
        int tn = T.size();
        std::vector<std::vector<int>>dp(sn + 1, std::vector<int>(tn + 1, sn + 1));
        dp[0][0] = 0;
        for(int i = 0; i <= sn; ++i) dp[i][0] = 0;
        std::string res(""); 
        for(int i = 1; i <= sn; ++i){
            for(int j = 1; j <= tn; ++j){
                dp[i][j] = dp[i - 1][j]  + 1;
                if(S[i - 1] == T[j - 1]) dp[i][j] = std::min(dp[i - 1][j - 1] + 1, dp[i][j]);
                if(j == tn && dp[i][j] <= sn && (res == "" || dp[i][j] < res.size())) res = S.substr(i - dp[i][j], dp[i][j]);
            }
        }
        return res;
    }
};
