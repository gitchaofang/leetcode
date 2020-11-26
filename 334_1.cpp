class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        std::pair<int,int> p({INT_MAX,INT_MAX});
        for(const int& d: nums){
            if(d > p.second) return true;
            p.first = std::min(d, p.first);
            if(d > p.first && d < p.second) p.second = d;
        }
        return false;
    }
};
