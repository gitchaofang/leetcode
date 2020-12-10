class Solution {
public:
    bool dc(TreeNode* node1, TreeNode* node2){
        if(!node1 && !node2) return true;
        if((!node1 && node2) || (node1 && !node2) || (node1 -> val != node2 ->val)) return false;
        bool left = dc(node1 -> left, node2 -> right);
        bool right = dc(node1 -> right, node2 ->left);
        return left && right;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return dc(root -> left, root -> right);
    }
};
