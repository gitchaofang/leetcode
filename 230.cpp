class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> st({root});
        while(st.top() -> left) st.push(st.top() -> left);
        for(int i = 0; i < k; ++i){
            if(i == k - 1) return st.top() -> val;
            TreeNode* node = st.top();
            st.pop();
            if(node -> right){ 
                st.push(node -> right);
                while(st.top() -> left) st.push(st.top() -> left);
            }
        }
        return 0;
    }
};
