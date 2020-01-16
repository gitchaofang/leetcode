class Solution {
public:
    void dfs(TreeNode* root, std::string& res,std::string str){
        str.insert(str.begin(),'a' + root -> val);
        if(!root -> left && !root -> right){
            if(res == "") res = str;
            else if(res > str) res = str;
        }
        if(root -> left ) dfs(root -> left,res,str);
        if (root -> right) dfs(root -> right,res,str);
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        if(!root) return "";
        std::string res = "";
        dfs(root,res,"");
        return res;
    }
};
