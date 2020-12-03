class Solution {
public:
    int checkRecord(int n) {
        if(n == 0) return 0;
        if(n == 1) return 3;
        int res = 0;
        int A = 1;
        std::pair<int,int> L({1,0}); /*0A 1A*/
        std::pair<int,int> P({1,0}); /*0A 1A*/
        std::pair<int,int> double_L({0,0});
        int mod = std::pow(10,9) + 7;
        for(int i = 2; i <= n; ++i){
            int new_A = 0;
            std::pair<int,int> new_L({0,0});
            std::pair<int,int> new_P({0,0});
            std::pair<int,int> new_double_L({0,0});
            /*A*/
            new_A = ((L.first + P.first)%mod + double_L.first) % mod;
            /*P*/
            new_P.first = ((P.first + L.first) % mod + (double_L.first) % mod) % mod;
            new_P.second = ((P.second + L.second) % mod + (double_L.second + A) % mod) % mod;
            /*L*/
            new_L.first = P.first;
            new_L.second = (P.second + A) % mod;
            /*double L*/
            new_double_L.first = L.first;
            new_double_L.second = L.second;
            /*update*/
            L = new_L;
            P = new_P;
            A = new_A;
            double_L = new_double_L;
        }
        
        return (A + (((P.first + P.second) % mod + (L.first + L.second) % mod) % mod + (double_L.first + double_L.second) % mod) % mod) % mod;
    }
};
