class Solution {
public:
    int check(const std::vector<int>& nums, const int& targ){
        int piece = 0;
        for(int i = 0; i < nums.size(); ++i){
            int cnt = 0;
            int j = i;
            while(j < nums.size() && cnt < targ) cnt+= nums[j++];
            if(cnt >= targ) ++piece;
            i = j - 1;
        }
        return piece;
    }
    int maximizeSweetness(vector<int>& sweetness, int K) {
        if(K > sweetness.size()) return -1;
        int left = INT_MAX;
        int right = 0;
        for(const int& d: sweetness){
            left = std::min(d, left);
            right += d;
        }
        if(K == sweetness.size()) return left;
        while(left < right){
            if(right - left == 1){
                if(check(sweetness, right) < K + 1) right = left;
                else return right;
            } 
            int mid = left + (right - left) / 2;
            if(check(sweetness,mid) >= K + 1) left = mid;
            else right = mid;
        }
        return left;
    }
};
