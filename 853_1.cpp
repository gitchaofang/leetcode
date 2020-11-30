class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size() == 0) return 0;
        std::vector<std::pair<double,double>> v;
        for(int i = 0; i < speed.size(); ++i) v.push_back({position[i], speed[i]});
        std::sort(v.begin(), v.end());
        double head = (target - v.back().first) / v.back().second;
        int res = 0;
        for(int i = v.size() - 1; i >= 0; --i){
            double t = (target - v[i].first) / v[i].second;
            if(t <= head) continue;
            ++res;
            head = t;
        }
        return res + 1;
    }
};
