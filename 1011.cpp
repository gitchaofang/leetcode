class Solution {
public:
    int div(const std::vector<int>& nums, const int& targ){
        int piece = 0;
        for(int i = 0; i < nums.size(); ++i){
            int cnt = 0;
            int j = i;
            while(j < nums.size() && cnt < targ) cnt += nums[j++];
            --j;
            if(cnt > targ) cnt -= nums[j--];
            ++piece;
            i = j;
        }
        return piece;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int left = INT_MIN;
        int right = 0;
        for(const int& d: weights){
            left = std::max(left, d);
            right += d;
        }
        while(left < right){
            int mid = left + (right - left) / 2;
            if(div(weights, mid) <= D) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
