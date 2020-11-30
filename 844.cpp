class Solution {
public:
    void backspace(std::string& str){
        for(int i = 0; i < str.size(); ++i){
            if(str[i] != '#') continue;
            int j = i;
            while(j < str.size() && str[j] == '#') ++j;
            if(j - i >= i){
                str.erase(0, j);
                i = -1;
            }
            else{
                i -= (j - i + 1);
                str.erase(i + 1, j - i - 1);
            }
        }
        return;
    }
    bool backspaceCompare(string S, string T) {
        backspace(S);
        backspace(T);
        return S==T;
    }
};
