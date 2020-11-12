class Solution {
public:
    int dfs(const int& cur, const int& m, const int& n, const int& len, std::vector<bool>& visited, const std::vector<std::vector<int>>& jump){
        if(len == n) return 1;
        int res = (len >= m) ? 1 : 0;
        visited[cur] = true;
        for(int i = 1; i <= 9; ++i){
            if(i == cur || visited[i] == true || visited[jump[i][cur]] == false) continue;
            visited[i] = true;
            res += dfs(i, m, n, len + 1, visited, jump);
            visited[i] = false;
        }
        visited[cur] = false;
        return res;
    }
    int numberOfPatterns(int m, int n) {
        std::vector<std::vector<int>> jump(10, std::vector<int>(10, 0));
        std::vector<bool> visited(10, false);
        visited[0] = true;
        jump[1][3] = jump[3][1] = 2;
        jump[1][7] = jump[7][1] = 4;
        jump[1][9] = jump[9][1] = 5;
        jump[2][8] = jump[8][2] = 5;
        jump[4][6] = jump[6][4] = 5;
        jump[3][9] = jump[9][3] = 6;
        jump[7][9] = jump[9][7] = 8;
        jump[3][7] = jump[7][3] = 5;
        int res = 0;
        res += 4 * dfs(1, m, n, 1, visited, jump);
        res += 4 * dfs(2, m, n, 1, visited, jump);
        res += dfs(5, m, n, 1, visited, jump);
        return res;
    }
};
