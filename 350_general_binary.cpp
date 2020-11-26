class Solution {
public:
    int binary_search(const std::vector<int>& v, const int64_t& targ){
        int left = 0;
        int right = v.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(v[mid] <= targ) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty() || nums2.empty()) return {};
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        std::vector<int> res;
        for(int i = 0; i < nums1.size(); ++i){
            int d = nums1[i];
            int cnt= 0;
            int pos = binary_search(nums2, d - 1);
            if(nums2[pos] == d){
                int pos_end = binary_search(nums2, d);
                cnt = (nums2[pos_end] == d) ? pos_end - pos + 1 : pos_end - pos;
            }
            int next_i = binary_search(nums1, d);
            if(nums1[next_i] == d){ 
                cnt = std::min(cnt, next_i - i + 1);
                i = next_i;
            }
            else{
                cnt = std::min(cnt, next_i - i);
                i = next_i - 1;
            }
            for(int j = 0; j < cnt; ++j) res.push_back(d);      
        }
        return res;
    }
};
