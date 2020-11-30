class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int n = tree.size();
        int res = 0;
        int left = 0;
        std::unordered_map<int,int>m;
        for(int i = 0; i < n; ++i){
            ++m[tree[i]];
            if(m.size() <= 2) res = std::max(i - left + 1, res);
            while(m.size() > 2){
                if(--m[tree[left++]] == 0) m.erase(tree[left - 1]);
            }
        }
        return res;
    }
};
