class Solution {
public:
    int binary_search(const std::vector<int>& v, int left, int right, const int& targ){
        if(v[right] <= targ) return right + 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(v[mid] <= targ) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    int dc(std::vector<int>& nums, const int& left, const int& right){
        if(right == left) return 0;
        int mid = left + (right - left) / 2;
        int res = dc(nums, left, mid);
        res += dc(nums, mid + 1, right);
        for(int i = left; i <= mid; ++i){
            int targ = nums[i] / 2;
            if(nums[i] < 0 || nums[i] % 2 == 0) --targ;
            int pos = binary_search(nums, mid + 1, right, targ);
            res += (pos - mid - 1);
        }
        std::vector<int> tv(right - left + 1);
        int left_pos = left;
        int right_pos = mid + 1;
        for(int i = 0; i < tv.size(); ++i){
            if(left_pos <= mid && right_pos <= right){
                if(nums[left_pos] < nums[right_pos]) tv[i] = nums[left_pos++];
                else tv[i] = nums[right_pos++];
            }
            else if(left_pos <= mid) tv[i] = nums[left_pos++];
            else tv[i] = nums[right_pos++];
        }
        for(int i = 0; i < tv.size(); ++i) nums[left + i] = tv[i];
        return res;
    }
    int reversePairs(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res = dc(nums, 0, nums.size() - 1);
        return res;
    }
};
