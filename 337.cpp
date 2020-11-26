class Solution {
public:
    std::pair<int,int> dfs(TreeNode* root){
        if(!root) return {0,0};
        std::pair<int,int>left = dfs(root -> left);
        std::pair<int,int>right = dfs(root -> right);
        std::pair<int,int>p = {root -> val + left.second + right.second,std::max(left.first,left.second) + std::max(right.first,right.second)};
        return p;
    }
    int rob(TreeNode* root) {
        std::pair<int,int>p = dfs(root);
        return std::max(p.first,p.second);
    }
};
