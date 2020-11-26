struct cmp{
    bool operator()(const std::pair<int,int>& p1, const std::pair<int,int>& p2){
        return p1.second > p2.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, cmp> pq;
        std::unordered_map<int,int>m;
        for(const int& d: nums) ++m[d];
        for(const std::pair<int,int>& p: m){
            pq.push(p);
            if(pq.size() > k) pq.pop();
        }
        std::vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
