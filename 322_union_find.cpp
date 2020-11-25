class Solution {
public:
    int find_root(const std::vector<int>& root, const int& cur){
        return (root[cur] == cur) ? cur : find_root(root, root[cur]);
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        std::vector<int> root(n,0);
        for(int i = 0; i < n; ++i) root[i] = i;
        std::vector<std::vector<int>> bond(n);
        for(const std::vector<int>& edge: edges){
            bond[edge[0]].push_back(edge[1]);
            bond[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < n; ++i){
            int head = find_root(root, i);
            for(const int& nb: bond[i]){
                root[find_root(root, nb)] = head;
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            if(root[i] == i) ++cnt;
        }
        return cnt;
    }
};
