class Solution {
public:
    int binary_search(const std::vector<int>& v, int left, int right, const int& targ){
        while(left < right){
            int mid = left + (right - left) / 2;
            if(v[mid] <= targ) left = mid + 1;
            else right = mid;
        }  
        return v[left] == targ ? left : left - 1;
    }
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        std::vector<int> sm(n + 1,0);
        for(int i = 1; i <= n; ++i) sm[i] = sm[i - 1] + nums[i - 1];
        int res = INT_MAX;
        for(int i = 1; i <= n; ++i){
            if(sm[i] < s) continue;
            int pos = binary_search(sm, 0, i, sm[i] - s);
            res = std::min(res, i - pos);
        }
        return res == INT_MAX ? 0 : res;
    }
};
