//test comment
//test for branch
// delete
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        std::vector<std::vector<bool>> dp(n + 1,std::vector<bool>(m + 1,false));
        dp[0][0] = true;
        for(int i = 0; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(j > 1 && p[j - 1] == '*'){
                    dp[i][j] = dp[i][j - 2] || (i > 0 && dp[i - 1][j] && (p[j - 2] == s[i - 1] || p[j - 2] == '.'));
                }
                else{
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[n][m];
    }
};
