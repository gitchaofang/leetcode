class Solution {
public:
    TreeNode* dc(const std::vector<int>& v, const int& left, const int& right){
        if(left > right) return nullptr;
        TreeNode* root = new TreeNode(v[left]);
        int mid = left + 1;
        while(mid <= right && v[mid] < v[left]) ++mid;
        root -> left = dc(v, left + 1, mid - 1);
        root -> right = dc(v, mid, right);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return dc(preorder,0,preorder.size() - 1);    
    }
};
