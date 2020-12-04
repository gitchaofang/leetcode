class Solution {
public:
    std::pair<int,int> dfs(TreeNode* root, int& res){
        if(!root -> left && !root -> right) return {root-> val,root->val};
        else if(root -> left && root -> right){
            int val = root -> val;
            std::pair<int,int> left = dfs(root -> left, res);
            std::pair<int,int> right = dfs(root -> right, res);
            int mx = std::max(left.first,right.first);
            int mn = std::min(left.second,right.second);
            res = std::max(std::max(abs(mx - val),abs(mn - val)),res);
            return {std::max(val,mx),std::min(val,mn)};
        }
        else if(root -> left){
            int val = root -> val;
            std::pair<int,int> left = dfs(root -> left,res);
            res = std::max(std::max(abs(val - left.first),abs(val - left.second)),res);
            return {std::max(val,left.first),std::min(val,left.second)};
        }
        else{
            int val = root -> val;
            std::pair<int,int> right = dfs(root -> right,res);
            res = std::max(std::max(abs(val - right.first),abs(val - right.second)),res);
            return {std::max(val,right.first),std::min(val,right.second)};    
        }
        return {};
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        dfs(root,res);
        return res;
    }
};
