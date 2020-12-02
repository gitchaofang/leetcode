struct cmp{
    bool operator()(const std::pair<int,int>& p1, const std::pair<int,int>& p2){
        return p1.second - p1.first < p2.second - p2.first;
    }  
};
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,cmp>pq;         int res = INT_MIN;
        for(int i = 0; i < points.size(); ++i){
            int x = points[i][0];
            while(!pq.empty() && pq.top().first< x - k) pq.pop();
            if(!pq.empty()) res = std::max(points[i][1] + points[i][0] + pq.top().second - pq.top().first, res);
            pq.push({points[i][0], points[i][1]});
        }
        return res;
    }
};
