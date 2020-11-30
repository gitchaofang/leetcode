class Solution {
public:
    int bfs(std::vector<std::vector<int>>& A, std::queue<int>& q){
        int cnt = 0;
        int row = A.size();
        int col = A[0].size();
        std::vector<std::pair<int,int>> dire({{0,-1},{-1,0},{0,1},{1,0}});
        while(!q.empty()){
            ++cnt;
            for(int i = q.size(); i > 0; --i){
                int cur = q.front();
                q.pop();
                for(const std::pair<int,int>& dir: dire){
                    int x = dir.first + cur / col;
                    int y = dir.second + cur % col;
                    if(x < 0 || x >= row || y < 0 || y >= col || A[x][y] == 2) continue;
                    if(A[x][y] == 1) return cnt - 1;
                    q.push(x * col + y);
                    A[x][y] = 2;
                }
            }
        }
        return -1;
    }
    int shortestBridge(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        std::vector<std::pair<int,int>> dire({{0,-1},{-1,0},{0,1},{1,0}});
        std::queue<int> ori_q;
        for(int i = 0; i < row * col; ++i){
            if(A[i / col][i % col] == 1){
                std::queue<int> q({i});
                A[i / col][i % col] = 2;
                while(!q.empty()){
                    for(int j = q.size(); j > 0; --j){
                        int cur = q.front();
                        ori_q.push(cur);
                        q.pop();
                        for(const std::pair<int,int>& dir: dire){
                            int x = dir.first + cur / col;
                            int y = dir.second + cur % col;
                            if(x < 0 || x >= row || y < 0 || y >=col || A[x][y] != 1) continue;
                            q.push(x * col + y);
                            A[x][y] = 2;
                        }
                    }
                }
                break;
            }
        }
        return bfs(A, ori_q); 
    }
};
