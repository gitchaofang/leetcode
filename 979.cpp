class Solution {
public:
    int dfs(TreeNode* root, int& res){
        if(!root) return 0;
        int left = dfs(root -> left, res);
        int right = dfs(root -> right, res);
        res += std::abs(left) + std::abs(right);
        return root -> val + left + right - 1;
         
    }
    int distributeCoins(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};
