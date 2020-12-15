class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        std::vector<std::vector<int>> bond(n);
        std::vector<bool> visited(n,false);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(M[i][j] == 0) continue;
                bond[i].push_back(j);
                bond[j].push_back(i);
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            if(visited[i] == true) continue;
            ++cnt;
            std::queue<int> q({i});
            visited[i] == true;
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(const int&nb: bond[cur]){
                    if(visited[nb] == true) continue;
                    visited[nb] = true;
                    q.push(nb);
                }
            }
        }
        return cnt;
    }
};
