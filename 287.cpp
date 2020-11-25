class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            int d = std::abs(nums[i]);
            if(nums[d] < 0) return d;
            nums[d] *= -1;
        }   
        return 0;
    }
};
