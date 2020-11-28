class Solution {
public:
    std::string trav(TreeNode* root, std::unordered_map<std::string,int>& m, std::vector<TreeNode*>& v){
        if(!root) return "#";
        std::string res = std::to_string(root -> val) +' ' +trav(root -> left, m, v) +' '+ trav(root -> right, m, v);
        if(m[res] == 1) v.push_back(root);
        ++m[res];
        return res;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        std::unordered_map<std::string, int> m;  
        std::vector<TreeNode*> v;
        trav(root, m, v);
        return v;
    }
};
