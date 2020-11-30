class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        std::vector<std::pair<int, std::vector<std::string>>> v;
        for(int i = 0; i < indexes.size(); ++i){
            std::vector<std::string> tv = {sources[i],targets[i]};
            v.push_back({indexes[i], tv});
        }
        std::sort(v.begin(),v.end());
        int off_set = 0;
        for(const std::pair<int, std::vector<std::string>>& p: v){
            if(S.substr(off_set + p.first, p.second[0].size()) != p.second[0]) continue;
            S.erase(off_set + p.first, p.second[0].size());
            S.insert(off_set + p.first, p.second[1]);
            off_set += p.second[1].size() - p.second[0].size();
        }
        return S;
    }
};
