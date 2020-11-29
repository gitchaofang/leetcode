class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        std::vector<int> dp(N + 1, INT_MAX);
        std::vector<std::vector<std::pair<int,int>>> bond(N + 1);
        for(const std::vector<int>& v: times) bond[v[0]].push_back({v[1], v[2]});
        std::queue<int> q({K});
        dp[K] = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(const std::pair<int,int>& nb: bond[cur]){
                int d = nb.second + dp[cur];
                if(d >= dp[nb.first]) continue;
                q.push(nb.first);
                dp[nb.first] = d;
            }
        }
        int res = 0;
        for(int i =1 ; i <= N; ++i){
            if(dp[i] == INT_MAX) return -1;
            res = std::max(res, dp[i]);
        }
        return res;
    }
};
