class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        std::vector<std::unordered_set<int>> bond(n);
        for(const std::vector<int>& v: connections){
            bond[v[0]].insert(v[1]);
            bond[v[1]].insert(-v[0]);
        }
        int res = 0;
        std::queue<int> q({0});
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(const int& nb: bond[cur]){
                bond[std::abs(nb)].erase(cur);
                if(nb > 0) ++res;
                q.push(std::abs(nb));
            }
        }
        return res;
    }
};
