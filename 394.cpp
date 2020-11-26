class Solution {
public:
    string decodeString(string s) {
        if(s == "") return s;
        std::string res;
        int n = s.size();
        for(int i = 0; i < n; ++i){
            if(s[i] >= '0' && s[i] <= '9'){
                int num = 0;
                int j = i;
                while(j < n && s[j] >= '0' && s[j] <= '9') num = num * 10  + (s[j++] - '0');
                int cnt = 1;
                ++j;
                int begin = j;
                while(j < n && cnt != 0){
                    if(s[j] == '[') ++cnt;
                    else if (s[j] == ']') --cnt;
                    ++j;
                }
                std::string str = decodeString(s.substr(begin, j - begin - 1));
                for(int r = 0; r < num; ++r) res += str;
                i = j - 1;
            }
            else res += s[i];
        }
        return res;
    }
};
