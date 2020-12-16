class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        std::unordered_map<int, std::unordered_set<int>> m;
        for(const std::vector<int>&v: points) m[v[0]].insert(v[1]);
        int res = INT_MAX;
        for(int i = 0; i < points.size(); ++i){
            for(int j = i + 1; j < points.size(); ++j){
                if(points[i][0] == points[j][0] || points[i][1]  == points[j][1] || (m[points[i][0]].find(points[j][1]) == m[points[i][0]].end()) || (m[points[j][0]].find(points[i][1]) == m[points[j][0]].end())) continue;
                res = std::min(res, std::abs(points[i][0] - points[j][0]) * std::abs(points[i][1] - points[j][1]));
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
