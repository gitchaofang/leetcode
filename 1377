class Solution {
public:
    double dfs(std::vector<std::unordered_set<int>>& bond, const int& cur, const int& des, const int& t){
        if(bond[cur].size() == 0 || t == 0){
            if(cur == des) return 1.0;
            else return 0;
        }
        double res = 0;
        double prob = 1.0 / double(bond[cur].size());
        for(const int& nb: bond[cur]){
            bond[nb].erase(cur);
            res += prob * dfs(bond, nb, des, t - 1);
        }
        return res;
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        std::vector<std::unordered_set<int>> bond(n + 1);
        for(const std::vector<int>& v: edges){ 
            bond[v[0]].insert(v[1]);
            bond[v[1]].insert(v[0]);
        }
        return dfs(bond, 1, target, t);
    }
};
