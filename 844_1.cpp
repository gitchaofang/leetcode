class Solution {
public:
    std::string back(const std::string& str){
        int cnt = 0;
        std::string res("");
        for(int i = str.size() - 1; i >= 0; --i){
            if(str[i] == '#') ++cnt;
            else if(cnt != 0) --cnt;
            else res.insert(res.begin(), str[i]);
        }
        return res;
    }
    bool backspaceCompare(string S, string T) {
        return back(S) == back(T);
    }
};
