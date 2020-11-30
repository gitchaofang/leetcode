class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        std::map<int,int>m;
        for(const int& d: hand) ++m[d];
        while(!m.empty()){
            int d = m.begin() -> first - 1;
            for(int i = 0; i < W; ++i){
                if(m.find(++d) == m.end()) return false;
                if(--m[d] == 0) m.erase(d); 
            }
        }
        return true;
    }
};
