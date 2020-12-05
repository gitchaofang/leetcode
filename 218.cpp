class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        std::map<int,std::vector<std::pair<int,int>>>m;
        for(const std::vector<int>& build: buildings){
            m[build[0]].push_back({build[2],1});
            m[build[1]].push_back({build[2], - 1});
        }
        std::map<int,int>high;
        int pre = 0;
        std::vector<std::vector<int>>res;
        for(auto it = m.begin(); it != m.end(); ++it){
            for(const std::pair<int,int>& p: it -> second){ 
                high[p.first] += p.second;  
                if(high[p.first] == 0) high.erase(p.first);
            }
            if(high.empty()){
                if(pre != 0){ 
                    res.push_back({it -> first,0});
                    pre = 0;
                }
            }
            else{
                if(high.rbegin() -> first != pre){
                    res.push_back({it -> first, high.rbegin() -> first});
                    pre = high.rbegin() -> first;
                }
            }
        }
        return res;
    }
};
