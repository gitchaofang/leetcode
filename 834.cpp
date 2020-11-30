class Solution {
public:
    void dfs(const int& cur, std::vector<std::unordered_set<int>>& bond, std::vector<int>& dis, std::vector<int>& cnt){
        if(bond[cur].size() == 0) return;
        for(const int& nb: bond[cur]){
            bond[nb].erase(cur);
            dfs(nb, bond, dis, cnt);
            dis[cur] += cnt[nb] + dis[nb];
            cnt[cur] += cnt[nb];
        }
        return;
    }
    void update(const int& cur, const std::vector<std::unordered_set<int>>& bond, std::vector<int>& dis, const std::vector<int>& cnt){
        if(bond[cur].size() == 0) return;
        int d = dis[cur];
        int n = cnt.size();
        for(const int& nb: bond[cur]){
            dis[nb] += d - (cnt[nb] + dis[nb]) + (n - cnt[nb]); 
            update(nb, bond,dis,cnt);
        }
        return;
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        if(N <= 1) return {0};
        std::vector<int> dis(N,0);
        std::vector<int> cnt(N,1);
        std::vector<std::unordered_set<int>> bond(N);
        for(const std::vector<int>& edge: edges){
            bond[edge[0]].insert(edge[1]);
            bond[edge[1]].insert(edge[0]);
        }
        
        dfs(0, bond, dis, cnt);
        update(0, bond,dis,cnt);
        return dis;
    }
};
