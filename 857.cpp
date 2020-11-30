class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        std::vector<std::pair<double, double>> v;
        for(int i = 0; i < wage.size(); ++i) v.push_back({double(wage[i]) / double(quality[i]), quality[i]});
        std::sort(v.begin(),v.end());
        std::priority_queue<int> pq;
        double qual = 0;
        double res = INT_MAX;
        for(int i = 0; i < wage.size(); ++i){
            qual += v[i].second;
            pq.push(v[i].second);
            if(pq.size() == K){
                res = std::min(v[i].first * qual, res);
                qual -= pq.top();
                pq.pop();
            }
        }
        return res;
    }
};
