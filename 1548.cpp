class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        int l = targetPath.size();
        std::vector<std::vector<int>> dp(l + 1, std::vector<int>(n,0));
        std::vector<std::vector<int>> bond(n);
        for(const std::vector<int>& v: roads){
            bond[v[0]].push_back(v[1]);
            bond[v[1]].push_back(v[0]);
        }
        int cnt = INT_MAX;
        int pos = 0;
        for(int s = 1; s <= l; ++s){
            for(int i = 0; i < n; ++i){
                int d = INT_MAX;
                for(const int& nb: bond[i]) d = std::min(d, dp[s - 1][nb]);
                dp[s][i] = (targetPath[s - 1] == names[i] ? d : 1 + d);
                if(s == l && dp[s][i] < cnt){ 
                    cnt = dp[s][i];
                    pos = i;
                }
            }
        }

        std::vector<int> res;
        for(int i = l; i > 0; --i){
            res.insert(res.begin(), pos);
            for(const int& nb: bond[pos]){
                if((names[pos] == targetPath[i - 1] && dp[i - 1][nb] == dp[i][pos]) || (names[pos] != targetPath[i - 1] && dp[i - 1][nb] + 1 == dp[i][pos])){ 
                    pos = nb;
                    break;
                }
            }
        }
        return res;
    }
};
