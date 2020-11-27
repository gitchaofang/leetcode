class Solution {
public:
    int dfs(TreeNode* root, int& res){
        if(!root) return -1;
        int left = dfs(root -> left, res) + 1;
        int right = dfs(root -> right, res) + 1;
        res = std::max(left + right, res);
        return std::max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        dfs(root,res);
        return res;
    }
};

