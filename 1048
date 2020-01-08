class Solution {
public:
    int longestStrChain(vector<string>& words) {
        if(words.empty()) return 0;
        std::map<int,std::vector<std::string>>m;
        std::unordered_map<std::string,int> dp;
        for(const std::string& str: words){ 
            m[str.size()].push_back(str);
            dp[str] = 1;
        }
        int res = 1;
        for(auto it = m.begin(); it != m.end(); ++it){
            if(it == m.begin()) continue;
            std::vector<std::string> v = it -> second;
            for(const std::string& str: v){
                for(int i=0; i<str.size(); ++i){
                    std::string ss = str;
                    ss.erase(ss.begin() + i);
                    if(dp.find(ss) == dp.end()) continue;
                    dp[str] = std::max(dp[str], dp[ss] + 1);
                    res = std::max(res,dp[str]);
                }
            }
        }
        return res;
    }
};
