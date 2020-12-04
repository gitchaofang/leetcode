class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size() - 1; ++i){
            if(nums[i] == nums[i + 1] - 1) continue;
            if(nums[i + 1] - nums[i]  - 1 >= k) return nums[i] + k;
            else k -= nums[i + 1] - nums[i] - 1;
        }   
        return nums.back() + k;
    }
};
