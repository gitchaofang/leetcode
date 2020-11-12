class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        std::pair<int,int> p{INT_MAX,INT_MAX};
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > p.second) return true;
            if(nums[i] > p.first && nums[i] < p.second) p.second = nums[i];
            if(nums[i] < p.first) p.first = nums[i];
        }
        return false;   
    }
};
