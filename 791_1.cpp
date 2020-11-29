class Solution {
public:
    string customSortString(string S, string T) {
        std::unordered_map<char,int>order;
        for(int i = 0; i < S.size(); ++i) order[S[i]] = i;
        std::vector<std::pair<char,int>> v;
        for(const char& c: T){
            if(order.find(c) == order.end()) v.push_back({c, - 1});
            else v.push_back({c, order[c]});
        }
        std::sort(v.begin(), v.end(), [](const std::pair<char,int>& p1, const std::pair<char, int>& p2){
            return p1.second < p2.second;
        });
        std::string res("");
        for(const std::pair<char,int>& p: v)res.push_back(p.first);
        return res;
    }
};
