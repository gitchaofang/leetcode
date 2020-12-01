class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int pos = 1;
        for(int i = n; i < 2*n; ++i){
            int d = nums[i];
            nums.insert(nums.begin() + pos, nums[i]);
            nums.erase(nums.begin() + i + 1);
            pos += 2;
        }
        return nums;
    }
};
