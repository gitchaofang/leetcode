class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        std::unordered_set<std::string> st(wordDict.begin(), wordDict.end());
        std::vector<bool> dp(n + 1, false);
        dp[n] = true;
        for(int i = n - 1; i >= 0; --i){
            for(const std::string& str: st){
                if(str.size() > n - i || s.substr(i, str.size()) != str || !dp[i + str.size()]) continue;
                dp[i] = true;
                break;
            }
        }
        return dp[0];
    }
};
