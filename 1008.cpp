class Solution {
public:
    int find_pivit(const std::vector<int>& v){
        int targ = v[0];
        int left = 1;
        int right = v.size() - 1;
        while(left < right){
            int mid = (right - left)/2 + left;
            if(v[mid] < targ) left = mid + 1;
            else right = mid;
        }
        return right;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return nullptr;
        int val = preorder[0];
        TreeNode* root = new TreeNode(val);
        if(preorder.size() == 1) return root;
        if(preorder[1] < val && preorder.back() > val){
            int pivit = find_pivit(preorder);
            std::vector<int> left_v(preorder.begin() + 1,preorder.begin() + pivit);
            preorder.erase(preorder.begin(), preorder.begin() + pivit);
            root -> left = bstFromPreorder(left_v);
            root -> right = bstFromPreorder(preorder);
        }
        else if(preorder[1] < val){
            preorder.erase(preorder.begin());
            root -> left = bstFromPreorder(preorder);
        }
        else{
            preorder.erase(preorder.begin());
            root -> right = bstFromPreorder(preorder);
        }
        return root;
    }
};
