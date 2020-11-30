class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        std::unordered_map<int,int>m;
        int name = 0;
        int cnt = 0;
        for(int i = 0; i < times.size(); ++i){
            if(++m[persons[i]] >= cnt){
                cnt = m[persons[i]];
                name = persons[i];
            }
            v.push_back({times[i],name});
        }
        return;
    }
    
    int q(int t) {
        int left = 0;
        int right = v.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(v[mid].first <= t) left = mid + 1;
            else right = mid;
        }
        if(v[left].first <= t) ++left;
        return v[--left].second;
    }
private:
    std::vector<std::pair<int,int>>v;
};
