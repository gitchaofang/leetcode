class Solution {
public:
    bool canTransform(string start, string end) {
        if(start.size() != end.size()) return false;
        std::vector<std::pair<char,int>>s;
        std::vector<std::pair<char,int>>e;
        for(int i = 0; i < start.size(); ++i){
            if(start[i] != 'X') s.push_back({start[i],i});
            if(end[i] != 'X') e.push_back({end[i], i});
        }
        if(s.size() != e.size()) return false;
        for(int i = 0; i < s.size(); ++i){
            if(s[i].first != e[i].first || (s[i].first == 'R' && s[i].second > e[i].second) || (s[i].first == 'L' && s[i].second  < e[i].second)) return false;
        }
        return true;
    }
};
