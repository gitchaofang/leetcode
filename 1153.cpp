class Solution {
public:
    bool canConvert(string str1, string str2) {
        if(str1 == str2) return true;
        std::unordered_map<int,std::vector<int>>m;
        for(int i = 0; i < str2.size(); ++i) m[str2[i] - 'a' + 1].push_back(i);
        if(m.size() == 26) return false;
        std::unordered_map<int,int> color;
        for(const std::pair<int, std::vector<int>>& p: m){
            int d = p.first;
            for(const int& nb: p.second){
                int co = str1[nb] + 1;
                if(color.find(co) == color.end()) color[co] = d;
                else if(color[co] != d) return false;
            }
        }
        return true;
    }
};
