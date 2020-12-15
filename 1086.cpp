struct cmp{
    bool operator()(const int& d1, const int& d2){
        return d1 > d2;
    }  
};
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        int n = items.size();
        std::map<int,std::priority_queue<int, std::vector<int>,cmp>>m;
        for(const std::vector<int>& p: items){
            m[p[0]].push(p[1]);
            if(m[p[0]].size() > 5) m[p[0]].pop();
        }
        std::vector<std::vector<int>> res;
        for(auto it = m.begin(); it != m.end(); ++it){
            int sm = 0;
            int size = it -> second.size();
            while(!it -> second.empty()){
                sm += it->second.top();
                it -> second.pop();
            }
            res.push_back({it -> first, sm / size});
        }
        return res;
    }
};
