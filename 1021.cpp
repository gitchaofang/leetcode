class Solution {
public:
    string removeOuterParentheses(string S) {
        for(int i = 0; i < S.size(); ++i){
            int j = i;
            int cnt = 1;
            while(cnt != 0){
                ++j;
                if(S[j] == ')') --cnt;
                else if(S[j] == '(') ++cnt;
            }
            S.erase(S.begin() + j);
            S.erase(S.begin() + i);
            i = j - 2;
        }    
        return S;
    }
};
