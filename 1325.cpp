class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return nullptr;
        TreeNode* left = removeLeafNodes(root -> left, target);
        TreeNode* right = removeLeafNodes(root -> right, target);
        if(root -> val == target && !left && !right) return nullptr;
        root -> left = left;
        root -> right = right;
        return root;
    }
};
