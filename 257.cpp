class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        std::vector<std::string> left = binaryTreePaths(root -> left);
        std::vector<std::string> right = binaryTreePaths(root -> right);
        if(left.empty() && right.empty()) return {std::to_string(root -> val)};
        if(!left.empty()){
            for(std::string& str: left) str.insert(0,std::to_string(root -> val) + "->");
        }
        if(!right.empty()){ 
            for(std::string& str: right) str.insert(0,std::to_string(root -> val) + "->");
        }
        left.insert(left.end(),right.begin(),right.end());
        return left;
    }
};
