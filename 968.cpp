class Solution {
public:
    int dfs(TreeNode* root, int& res){
        if(!root) return 0;
        int left = dfs(root -> left, res);
        int right = dfs(root -> right, res);
        /*no cover*/
        if(left == 0 && right == 0){ 
            ++res;
            return 2;
        }
        /* cover but no cam*/
        if((left == 1 && right != 2) || (right == 1 && left != 2)) return 0;
        /*cover with 1 cam*/
        if((left == 2 && right != 2) || (right == 2 && left != 2)) return 1;
        /*cover with two cams*/
        if(right == 2 && left == 2){
            --res;
            return 1;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};
