class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        std::vector<int> sm(n + 1, 0);
        int res = n + 1;
        int left = 0;
        for(int i = 1; i <= n; ++i){
            sm[i] = sm[i - 1] + nums[i - 1];
            while(sm[i] - sm[left] >= s) res = std::min(res,i - left++);
        }
        return res == n + 1 ? 0 : res;
    }
};
