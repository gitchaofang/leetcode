class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        std::vector<std::vector<int>> res;
        for(int i = 0; i < s.size(); ++i){
            int j = i;
            while(j < s.size() && s[j] == s[i]) ++j;
            if(j - i >= 3) res.push_back({i, j - 1});
            i = j - 1;
        }
        return res;
    }
};
