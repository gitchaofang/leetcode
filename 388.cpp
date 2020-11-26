lass Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        std::unordered_map<std::string, std::vector<std::pair<std::string,double>>> m;
        for(int i = 0; i < equations.size(); ++i){
            m[equations[i][0]].push_back({equations[i][1],values[i]});
            m[equations[i][1]].push_back({equations[i][0],1.0 / values[i]});
        }       
        std::vector<double> res;
        for(const std::vector<std::string>& v: queries){
            if(m.find(v[0]) == m.end())res.push_back(-1.0);
            else if(v[0] == v[1]) res.push_back(1.0);
            else{
                std::queue<std::pair<std::string,double>>q({{v[0],1.0}});
                std::unordered_set<std::string> visited({v[0]});
                bool found = false;
                while(!q.empty()){
                    std::string cur = q.front().first;
                    double val = q.front().second;
                    q.pop();
                    for(const std::pair<std::string, double>& p: m[cur]){
                        if(visited.find(p.first) != visited.end()) continue;
                        if(p.first == v[1]){
                            res.push_back(val * p.second);
                            found = true;
                        }
                        visited.insert(p.first);
                        q.push({p.first,val * p.second});
                    }
                    if(found == true) break;
                }
                if(found == false) res.push_back(-1.0);
            }
        }
        return res;
    }
};
