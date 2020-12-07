class Solution {
public:
    void dfs(const int& cur, std::vector<std::vector<int>>& bond, std::vector<int>& id, const int& par){
        for(const int& nb: bond[cur]){
            if(nb == par) continue;
            if(id[nb] == -1){
                id[nb] = id[cur] + 1;
                dfs(nb, bond, id, cur);
            }
            else if(id[nb] > id[cur]){
                id[nb] = id[cur];
                dfs(nb, bond, id, cur);    
            }
            id[cur] = std::min(id[nb],id[cur]);
        }
        return;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        std::vector<int> id(n, -1);
        std::vector<std::vector<int>> bond(n);
        for(const std::vector<int>& v: connections){
            bond[v[0]].push_back(v[1]);
            bond[v[1]].push_back(v[0]);
        }
        
        id[0] = 0;
        dfs(0, bond, id, -1);
        std::vector<std::vector<int>> res;
       
        for(const std::vector<int>& v: connections){
            if(id[v[0]] != id[v[1]]) res.push_back(v);
        }
        return res;
    }
};
