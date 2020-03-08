#include<numeric>
class Solution {
public:
    Solution(vector<int>& w) {
        v = w;
        for(int i=1; i<w.size(); ++i) v[i] = v[i-1] + w[i];
    }
    
    int pickIndex() {
        int ind = rand() % (v.back());
        int left = 0;
        int right = v.size() - 1;
        while(left < right){
            int mid = (right - left)/2 + left;
            if(v[mid] <= ind) left = mid + 1;
            else right = mid;
        }
        return right;
    }
private:
    std::vector<int> v;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
