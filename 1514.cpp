class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        std::vector<double> dp(n,0);
        dp[start] = 1.0;
        std::vector<std::vector<std::pair<int,double>>> bond(n);
        for(int i = 0; i < edges.size(); ++i){
            bond[edges[i][0]].push_back({edges[i][1],succProb[i]});
            bond[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        std:queue<int> q({start});
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(const std::pair<int,double>& nb: bond[cur]){
                double prob = nb.second * dp[cur];
                if(prob <= dp[nb.first]) continue;
                dp[nb.first] = prob;
                q.push(nb.first);
            }
        }
        return dp[end];
    }
};
