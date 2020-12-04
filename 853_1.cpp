class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n <= 1) return n;
        std::vector<std::pair<int,double>>v;
        for(int i = 0; i < n; ++i){
            v.push_back({position[i], double(target - position[i]) / double(speed[i])});
        }
        std::sort(v.begin(),v.end());
        for(int i = v.size() - 2; i >= 0; --i){
            if(v[i].second <= v[i + 1].second){
                --n;
                v[i].second = v[i + 1].second;
            }
        }
        return n;
    }
};
