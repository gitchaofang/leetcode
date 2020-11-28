class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::unordered_map<char,int>m;
        for(const char& c: tasks) ++m[c];
        std::vector<int>time;
        for(const std::pair<char,int>& p: m) time.push_back(p.second);
        std::sort(time.begin(),time.end());
        int gap = (time.back() - 1) * n;
        for(int i = time.size() - 2; i >= 0; --i){
            gap -= std::min(time[i], time.back() - 1);
        }
        return std::max(gap, 0) + tasks.size();
    }
};
