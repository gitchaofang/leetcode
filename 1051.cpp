class Solution {
public:
    int heightChecker(vector<int>& heights) {
        std::vector<int> ori = heights;
        std::sort(heights.begin(), heights.end());
        int cnt = 0;
        for(int i = 0; i < ori.size(); ++i){
            if(ori[i] != heights[i]) ++cnt;   
        }
        return cnt;
    }
};
