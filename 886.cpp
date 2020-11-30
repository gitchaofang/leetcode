class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        std::vector<std::vector<int>> dis(N + 1);
        for(const std::vector<int>&v: dislikes){
            dis[v[0]].push_back(v[1]);
            dis[v[1]].push_back(v[0]);
        }
        std::vector<int> color(N + 1, -1);
        for(int i = 1; i <= N; ++i){
            if(color[i] != -1) continue;
            std::queue<int> q({i});
            color[i] = 0;
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(const int& nb: dis[cur]){
                    if(color[nb] == -1){
                        color[nb] = (color[cur] + 1) % 2;
                        q.push(nb);
                    }
                    else if(color[nb] == color[cur]) return false;
                }
            }
        }
        return true;
    }
};
