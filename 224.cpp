class Solution {
public:
    int calculate(string s) {
        int res = 0;
        int sign = 1;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ' ') continue;
            if(s[i] == '-') sign = -1;
            else if(s[i] == '+') sign = 1;
            else if(s[i] <= '9' && s[i] >= '0'){
                int num = 0;
                int j = i;
                while(j < s.size() && s[j] <= '9' && s[j] >= '0') num = num * 10 + (s[j++] - '0');
                i = j - 1;
                res += sign * num;
            }
            else if(s[i] == '('){
                int j = i + 1;
                int cnt = 1;
                while(cnt != 0){
                    if(s[j] == '(') ++cnt;
                    else if(s[j] == ')') --cnt;
                    ++j;
                }
                int d = calculate(s.substr(i + 1, j - 1 - i));
                res += sign*d;
                i = j - 1;
            }
        }
        return res;
    }
};
