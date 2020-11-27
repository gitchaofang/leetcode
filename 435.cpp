lass Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::map<int,int>m;
        for(const std::vector<int>& v: intervals){
            if(m.find(v[0]) == m.end()) m[v[0]] = v[1];
            else m[v[0]] = std::min(m[v[0]], v[1]);
        }
        int pre = INT_MIN;
        int cnt = m.size();
        for(auto it = m.begin(); it != m.end(); ++it){
            if(it -> first < pre){ 
                --cnt;
                pre = std::min(it -> second, pre);
            }
            else pre = it -> second;
        }
        return intervals.size() - cnt;
    }
};
