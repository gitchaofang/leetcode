class Solution {
public:
    string reverseVowels(string s) {
        std::vector<int> pos;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == 'a' || s [i]== 'e' || s[i] == 'i' || s[i] =='o'|| s[i] == 'u' || s[i] == 'A' || s [i]== 'E' || s[i] == 'I' || s[i] =='O'|| s[i] == 'U') pos.push_back(i);
        }
        for(int i = 0; i < pos.size() / 2; ++i) std::swap(s[pos[i]], s[pos[pos.size() - 1 - i]]);
        return s;
    }
};
