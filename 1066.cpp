class Solution {
public:
    int dfs(const std::vector<std::vector<int>>& bike, const std::vector<std::vector<int>>& worker, const int& cur, int& visited, std::unordered_map<std::string, int>& m){
        if(cur == worker.size()) return 0;
        std::string str = std::to_string(cur) + '-' + std::to_string(visited);
        if(m.find(str) != m.end()) return m[str];
        int res = INT_MAX;
        for(int i = 0; i < bike.size(); ++i){
            int mask = 1 << i;
            if((visited & mask) != 0) continue;
            int d = std::abs(worker[cur][0] - bike[i][0]) + std::abs(worker[cur][1] - bike[i][1]);
            visited |= mask;
            res = std::min(res, d + dfs(bike, worker, cur + 1, visited, m));
            visited ^= mask;
        } 
        m[str] = res;
        return res;
    }
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int visited = 0;
        std::unordered_map<std::string, int>m;
        return dfs(bikes, workers, 0, visited, m);
    }
};
