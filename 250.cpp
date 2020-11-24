class Solution {
public:
    bool dfs(TreeNode* root, int& res){
        if(!root) return true;
        bool left = dfs(root -> left, res);
        bool right = dfs(root -> right, res);
        if(left && right && ((root -> left && root -> val == root -> left -> val) ||!root -> left ) && ((root -> right && root -> val == root -> right -> val) || !root -> right)){
            ++res;
            return true;
        }
        return false;
    }
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};
