class Solution {
public:
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& res){
        if(!root) return 0;
        int left = dfs(root -> left, p, q, res);
        int right = dfs(root -> right, p, q, res);
        if(root == p || root == q){
            if(left + right == 1) res = root;
            return left + right + 1;
        }
        if(left == 2 || right == 2) return 2;
        if(left + right == 2) res = root;
        return left + right;
    } 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* common_ancestor = nullptr;
        dfs(root, p, q, common_ancestor);
        return common_ancestor;
    }
};
