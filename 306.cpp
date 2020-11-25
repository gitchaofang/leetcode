class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for(int i = 0; i < n - 2; ++i){
            if(i > 0 && num[0] == '0') return false;
            for(int j = i + 1; j < n - 1; ++j){
                if(num[i + 1] == '0' && j - i > 1) break;
                std::string pre = num.substr(0, i + 1);
                std::string cur = num.substr(i + 1, j - i);
                int64_t pre_d = std::stol(pre);
                int64_t cur_d = std::stol(cur);
                std::string tot = pre + cur;
                while(tot.size() < n){
                    std::string ts = cur;
                    int64_t td = cur_d;
                    cur_d += pre_d; 
                    cur = std::to_string(cur_d);
                    pre_d = td;
                    pre = ts;
                    tot += cur;
                }
                if(tot == num) return true;
            }    
        }
        return false;
    }
};
