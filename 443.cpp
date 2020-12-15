class Solution {
public:
    int compress(vector<char>& chars) {
        for(int i = 0; i < chars.size(); ++i){
            int j = i;
            while(j < chars.size() && chars[j] == chars[i]) ++j;
            if(j - i > 1){
                std::string cnt = std::to_string(j - i);
                chars.erase(chars.begin() + i + 1, chars.begin() + j);
                for(int k = 1; k <= cnt.size(); ++k){ 
                    chars.insert(chars.begin() + i + k, cnt[k - 1]);
                }
                i += cnt.size();
            }
        }
        return chars.size();
    }
};
