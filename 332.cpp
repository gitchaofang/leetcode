class Solution {
public:
    void dfs(std::string des, std::unordered_map<std::string,multiset<std::string>>& m,std::vector<std::string>& res){ 
        while(!m[des].empty()){
            std::string next = *m[des].begin();
            m[des].erase(m[des].begin());
            dfs(next,m,res);
        }
        res.insert(res.begin(),des);
        return;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        std::unordered_map<std::string,std::multiset<std::string>>m;
        for(std::vector<std::string>& v: tickets) m[v[0]].insert(v[1]);
        std::vector<std::string> res;
        dfs("JFK",m,res);
        return res;
    }
};
