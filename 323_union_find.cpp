class Solution {
public:
    int find_root(const std::vector<int>& root, const int& d){
        return root[d] == d ? d : find_root(root, root[d]); 
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        std::vector<int> root(n);
        for(int i = 0; i < n; ++i) root[i] = i;
        for(const std::vector<int>& edge: edges){
            int q = find_root(root, edge[0]);
            int p = find_root(root, edge[1]);
            root[p] = q;
        }
        int res = 0;
        for(int i = 0; i < n; ++i) res += (i == root[i]);
        return res;
    }
};
