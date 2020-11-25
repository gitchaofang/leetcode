lass Solution {
public:
    int binary_search(const std::vector<int>& v, int left, int right, const int& targ){
        if(v[left] >= targ) return left;
        if(v[right] < targ) return right + 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(v[mid] < targ) left = mid + 1;
            else right = mid;
        }    
        return left;
    }
    void dc(std::vector<int>& nums, std::vector<int>& cnt, int left, int right){
        if(left == right) return;
        int mid = left + (right - left) / 2;
        dc(nums, cnt, left, mid);
        dc(nums, cnt, mid + 1, right);
        for(int i = left; i <= mid; ++i){
            int d = binary_search(nums, mid + 1, right, ori[i]);
            cnt[i] += d - mid - 1;
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
        return;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        ori = nums;
        std::vector<int>cnt(n,0);
        dc(nums, cnt, 0, nums.size() - 1);
        return cnt;
    }
private:
    std::vector<int> ori;
};
