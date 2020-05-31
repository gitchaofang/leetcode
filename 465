class Solution {
public:
    int tran(std::vector<int>& v,int start){
        int len = v.size();
        while(start < len && v[start] == 0) ++start;
        if(start == len) return 0;
        int res = INT_MAX;
        for(int i = start + 1; i < len; ++i){
            if(v[i]*v[start] >= 0) continue;
            v[i] += v[start];
            int tr = tran(v, start + 1);
            res = std::min(res,tr);
            v[i] -= v[start];
        }
        return res + 1;
    }
    int minTransfers(vector<vector<int>>& transactions) {
        std::unordered_map<int,int> m;
        for(const std::vector<int>& v: transactions){
            m[v[0]] += v[2];
            m[v[1]] -= v[2];
        }
        std::vector<int> acc;
        for(const std::pair<int,int>&p: m){
            if(p.second == 0) continue;
            acc.push_back(p.second);
        }
        return tran(acc,0);
    }
};
