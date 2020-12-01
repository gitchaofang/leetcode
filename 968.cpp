class Solution {
public:
    int dfs(TreeNode* root, int& cnt){
        if(!root) return 0;
        int l = dfs(root -> left, cnt);
        int r = dfs(root -> right, cnt);
        if(l == 2 || r == 2){
            if(l == r) --cnt;
            return 1;
        }
        else if(l == 1 || r == 1) return 0;
        ++cnt;
        return 2;
    }
    int minCameraCover(TreeNode* root) {
        int cnt = 0;
        dfs(root, cnt);
        return cnt;
    }
};
