class cmp{
    public:
        bool operator()(std::pair<std::string,int>& p1,std::pair<std::string,int>& p2){
            if (p1.second == p2.second)return p1.first > p2.first;
            return p1.second < p2.second;
        }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::unordered_map<std::string,int>um;
        for (std::string& s:words) ++um[s];
        std::priority_queue<std::pair<std::string,int>,std::vector<std::pair<std::string,int>>,cmp> pq({um.begin(),um.end()});
        std::vector<std::string> res;
        for (int i=0;i<k;++i){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
