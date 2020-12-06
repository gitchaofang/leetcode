class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<int> in(numCourses,0);
        std::vector<std::vector<int>> bond(numCourses);
        for(const std::vector<int>&v: prerequisites){
            bond[v[1]].push_back(v[0]);
            ++in[v[0]];
        }
        std::queue<int>q;
        for(int i = 0; i < numCourses; ++i){
            if(in[i] == 0) q.push(i);
        }
        std::vector<int> res;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            res.push_back(cur);
            for(const int&d: bond[cur]){
                --in[d];
                if(in[d] == 0) q.push(d);
            }
        }
        for(const int&d: in){
            if(d != 0) return {};
        }
        return res;
    }
};
