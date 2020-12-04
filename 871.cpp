class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        std::sort(stations.begin(), stations.end());
        int cur = 0;
        std::priority_queue<int> pq;
        int res = 0;
        for(;startFuel < target; ++res){
            while(cur < stations.size() && stations[cur][0] <= startFuel) pq.push(stations[cur++][1]);
            if(pq.empty()) return -1;
            startFuel += pq.top();
            pq.pop();
        }
        return res;
    }
};
