iclass Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        std::unordered_map<int,int>m;
        for(int i = 0; i < org.size(); ++i) m[org[i]] = i;
        std::vector<bool> flag(org.size(), false);
        flag.back() = true;
        for(const std::vector<int>& v: seqs){
            for(int i = 0; i < v.size() - 1; ++i){
                if(m.find(v[i]) == m.end() || m[v[i]] >= m[v[i + 1]]) return false;
                if(m[v[i]] < org.size() - 1 && org[m[v[i]] + 1] == v[i + 1]) flag[m[v[i]]] = true;
            }
            if(m.find(v.back()) == m.end()) return false;
        }

        for(bool val: flag){
            if(val == false) return false;
            
        }
        return seqs.empty() ? false: true;
    }
};
