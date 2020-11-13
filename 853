class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n == 0) return 0;
        std::vector<std::pair<double,double>> v;
        for(int i = 0; i < n; ++i) v.push_back({position[i],speed[i]});
        std::sort(v.begin(),v.end(),[](const std::pair<int,int>& p1, const std::pair<int,int>& p2){
            return p1.first < p2.first;
        });
        std::pair<double, double> head({v.back()});
        for(int i = position.size() - 2; i >= 0; --i){
            if((target - v[i].first) / v[i].second <= (target - head.first) / head.second) --n;
            else head = v[i];
        }
        return n;
    }
};
