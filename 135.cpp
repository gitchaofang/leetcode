class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        std::vector<int> sm(n, 0);
        sm[0] = 1;
        for(int i = 1; i < ratings.size(); ++i){
            if(ratings[i] > ratings[i - 1]) sm[i] = sm[i - 1] + 1;
            else sm[i] = 1;
        }
        for(int i = n - 2; i >=0; --i){
            if(ratings[i] > ratings[i + 1]) sm[i] = std::max(sm[i + 1] + 1, sm[i]);
        }
        int res = 0;
        for(const int& d: sm) res += d;
        return res;
    }
};
