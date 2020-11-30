class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        std::map<int,int>m;
        for(const int& d: nums) ++m[d];
        while(!m.empty()){
            int d = m.begin() -> first - 1;
            for(int i = 0; i < k; ++i){
                if(m.find(++d) == m.end()) return false;
                if(--m[d] == 0) m.erase(d); 
            }
        }
        return true;    
    }
};
