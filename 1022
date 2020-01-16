class Solution {
public:
    void dfs(TreeNode* root, std::string s,std::vector<std::string>& store){
        char c = (root->val == 1) ? '1':'0';
        s.insert(s.end(),c);
        if(!root -> left && !root -> right) {
            store.push_back(s);
            return;
        }
        if(root -> left) dfs(root -> left, s, store);
        if(root -> right) dfs(root -> right,s, store);
        return;
        
    }
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        std::vector<std::string> store;
        dfs(root,"",store);
        int res = 0;
        for(const std::string& str:store){
            int sum = 0;
            for(const char& c: str){
                sum*=2;
                sum += (c == '1') ? 1 : 0;
            
            }
            res += sum;
        }
        return res;
    }
};
