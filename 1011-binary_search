class Solution {
public:
    int min_k(const std::vector<int>& v, const int& targ){
        int sum = 0;
        int k = 0;
        for(const int& d: v){
            sum += d;
            if(sum > targ){
                ++k;
                sum = d;
            }
        }
        ++k;
        return k;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int len = weights.size();
        int low = INT_MIN;
        int high = std::accumulate(weights.begin(),weights.end(),0);
        for(const int& d: weights){
            if(d > low) low = d;
        }
        while(low < high){
            int mid = (high - low) / 2 + low;
            if(min_k(weights,mid) <= D) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};
