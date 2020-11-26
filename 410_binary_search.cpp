class Solution {
public:
    int check(const vector<int>& v, const int& targ){
        int cnt = 0;
        int sm = 0;
        for(int i = 0; i < v.size(); ++i){
            sm += v[i];
            if(sm > targ){
                sm -= v[i];
                --i;
                ++cnt;
                sm = 0;
            }
        }
        return cnt + 1;
    }
    int splitArray(vector<int>& nums, int m) {
        int left = INT_MIN;
        int right = 0;
        for(const int& d: nums){
            left = std::max(left, d);
            right += d;
        }
        while(left < right){
            int mid = left + (right - left) / 2;
            int d = check(nums, mid);
            if(d <= m) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
