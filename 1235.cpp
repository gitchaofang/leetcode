class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        std::vector<std::vector<int>> v;
        int n = startTime.size();
        for(int i = 0; i < n; ++i) v.push_back({endTime[i],startTime[i],profit[i]});
        std::sort(v.begin(),v.end());
        
        std::map<int,int>m({{0,0}});
        int res = 0;
        for(const std::vector<int>& tv: v){
            int pro = std::prev(m.upper_bound(tv[1])) -> second + tv[2];
            if(m.rbegin() -> second < pro) m[tv[0]] = pro;
        }
        return m.rbegin() -> second;
    }
};
