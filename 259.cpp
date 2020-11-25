class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 3) return 0;
        std::sort(nums.begin(), nums.end());
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            int d = nums[i];
            int left = i + 1;
            int right = n - 1;
            while(left < right){
                int sm = d + nums[left] + nums[right];
                if(sm < target){
                    cnt += right - left;
                    ++left;
                }
                else --right;
            }
        }
        return cnt;
    }
};
