class Solution {
public:
    double dfs(const std::string& cur, std::unordered_set<std::string>& visited, std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>& m, const std::string& targ){
        if(cur == targ) return 1.0;
        double res = -1.0;
        std::string comb = cur + targ;
        if(result.find(comb) != result.end()) return result[comb];
        visited.insert(cur);
        for(const std::pair<std::string, double>& nb: m[cur]){
            if(visited.find(nb.first) != visited.end()) continue;
            double r = dfs(nb.first, visited, m, targ);
            if(r != -1.0){
                res = nb.second * r;
                break;
            }
        }
        visited.erase(cur);
        result[comb] = res;
        return res;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> m;
        for(int i = 0; i < values.size(); ++i){
            m[equations[i][0]].push_back({equations[i][1], values[i]});
            m[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        std::vector<double> res;
        std::unordered_set<std::string> visited;
        for(const std::vector<std::string>& query: queries){
            if(m.find(query[0]) == m.end()) res.push_back(-1.0);
            else res.push_back(dfs(query[0], visited, m, query[1]));
        }
        return res;
    }
private:
    std::unordered_map<std::string, double> result;
};
