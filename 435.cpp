class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        std::sort(intervals.begin(), intervals.end());
        int end = intervals[0][0];
        int res = 0;
        for(int i = 0; i < intervals.size(); ++i){
            if(intervals[i][0] >= end) end = intervals[i][1];
            else {
                ++res;
                end = std::min(end,intervals[i][1]);
            }
        }
        return res;
    }
};
