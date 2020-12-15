class Solution {
public:
    int find_root(const std::vector<int>& root, const int& d){
        return (root[d] == d) ? d : find_root(root, root[d]);
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        std::vector<int> root(n);
        for(int i = 0; i < n; ++i) root[i] = i;
        for(int i = 0; i < n; ++i){
            int p = find_root(root,i);
            for(int j = 0; j < n; ++j){
                if(M[i][j] == 0) continue;
                root[find_root(root,j)] = p;
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            if(root[i] == i) ++cnt;
        }
        return cnt;
    }
};
