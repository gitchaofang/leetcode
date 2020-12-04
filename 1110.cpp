class Solution {
public:
    void dfs(TreeNode* root, std::vector<TreeNode*>& res, const std::unordered_set<int>& st){
        if(!root) return;
        dfs(root -> left, res, st);
        dfs(root -> right, res, st);
        int d = root -> val;
        if(st.find(d) != st.end()){
            if(root -> left && st.find(root -> left -> val) == st.end()) res.push_back(root -> left);
            if(root -> right && st.find(root -> right -> val) == st.end()) res.push_back(root -> right);
        }
        else{
            if(root -> left && st.find(root -> left -> val) != st.end()) root -> left = nullptr;
            if(root -> right && st.find(root -> right -> val) != st.end()) root -> right = nullptr;
        }
        return;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root) return {};
        std::vector<TreeNode*> res;
        std::unordered_set<int>st(to_delete.begin(),to_delete.end());
        dfs(root, res, st);
        if(st.find(root -> val) == st.end()) res.push_back(root);
        return res;
    }
};
