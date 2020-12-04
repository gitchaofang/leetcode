class Solution {
public:
    int dist(std::vector<int>& p1, std::vector<int>& p2){
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        std::vector<int> w(workers.size(),-1);
        std::vector<int>b(bikes.size(),-1);
        std::vector<std::pair<int,int>>v;
        for(int i = 0; i < workers.size(); ++i){
            for(int j = 0; j < bikes.size(); ++j) v.push_back({i,j});
        }
        auto cmp = [&](std::pair<int,int>& p1,std::pair<int,int>& p2){
            int d1 = dist(workers[p1.first],bikes[p1.second]);
            int d2 = dist(workers[p2.first],bikes[p2.second]);
            if(d1 == d2){
                if(p1.first == p2.first) return p1.second < p2.second;
                return p1.first < p2.first;
            }
            return d1 < d2;
        };
        std::sort(v.begin(),v.end(),cmp);
        for(int i=0;i<v.size();++i){
            int wi = v[i].first;
            int bi = v[i].second;
            if(w[wi] != -1  || b[bi] != -1) continue;
            w[wi] = bi;
            b[bi] = 1;
        }
        return w;
    }
};
