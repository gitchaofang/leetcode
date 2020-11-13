class Solution {
public:
    string customSortString(string S, string T) {
        std::unordered_set<char> st(S.begin(), S.end());
        std::unordered_map<char,int> m;
        for(const char& c: T) ++m[c];
        std::string res("");
        for(char& c: T){
            if(st.find(c) == st.end()) res += c;
        }
        for(char&c: S){
            if(m.find(c) != m.end()) res.insert(res.end(),m[c],c);
        }
        return res;
    }
};
