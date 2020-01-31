class Solution {
public:
   void rec(std::string cur, std::unordered_map<std::string,std::multiset<std::string>>& m, std::vector<std::string>& res ){
        while(!m[cur].empty()){
            std::string des = *m[cur].begin();
            m[cur].erase(m[cur].begin());
            rec(des,m,res);
        }
        res.insert(res.begin(),cur);
        return;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        std::unordered_map<std::string,std::multiset<std::string>>m;
        for(const std::vector<std::string>& v:tickets) m[v[0]].insert(v[1]);
        std::vector<std::string> res;
        rec("JFK",m,res);
        return res;
    }
};
