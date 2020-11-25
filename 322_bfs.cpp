class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        std::vector<bool> visited(n,false);
        std::vector<std::vector<int>> bond(n);
        for(const std::vector<int>& edge: edges){
            bond[edge[0]].push_back(edge[1]);
            bond[edge[1]].push_back(edge[0]);
        }
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            if(visited[i]) continue;
            ++cnt;
            std::queue<int> q({i});
            visited[i] = true;
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(const int& nb: bond[cur]){
                    if(visited[nb]) continue;
                    q.push(nb);
                    visited[nb] = true;
                }
            }
        }
        return cnt;
    }
};
