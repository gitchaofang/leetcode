class Solution {
public:
    void write_sum(const std::vector<std::vector<int>>& nums, const int& k, int& sm, std::unordered_map<int,int>& m){
        if(k == nums.size()){ 
            ++m[sm];
            return;
        }
        for(const int& d: nums[k]){
            sm += d;
            write_sum(nums, k + 1, sm, m);
            sm -= d;
        }
        return;
    }
    void ksum(const std::vector<std::vector<int>>& nums, const int& k, int& sm, std::unordered_map<int,int>& m, int& res){
        if(k == nums.size()){
            if(m.find(-sm) != m.end()) res += m[-sm];
            return;
        }
        for(const int& d: nums[k]){
            sm += d;
            ksum(nums, k + 1, sm, m, res);
            sm -=d;
        }
        return;
    }
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        std::unordered_map<int,int> m;
        int sm = 0;
        write_sum({A,B}, 0, sm, m);
        int res = 0;
        ksum({C,D}, 0, sm, m, res);
        return res;
    }
};
