class Solution {
public:
    int binary_search(const std::vector<int>& v, const int& targ){
        int left = 0;
        int right = v.size() - 1;
        while(left < right){
            int mid = (right - left) / 2 + left;
            if(v[mid] < targ) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        std::vector<int> res({nums[0]});
        for(int i = 1; i < len; ++i){
            if(nums[i] > res.back()) res.push_back(nums[i]);
            else if(nums[i] < res.front()) res[0] = nums[i];
            else{
                int pos = binary_search(res,nums[i]);
                res[pos] = nums[i];
            }
        }
        return res.size();
    }
};
