class Solution {
public:
    int dfs(TreeNode* root, int& res){
        if(!root) return 0;
        int left = dfs(root -> left, res);
        int right = dfs(root -> right, res);
        int path = 1;
        if(left != 0 && root -> val + 1 == root -> left -> val) path = left + 1;
        if(right != 0 && root -> val + 1 == root -> right -> val) path = std::max(path, right + 1);
        res = std::max(path,res);
        return path;
    }
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        dfs(root , res);
        return res;
    }
};
