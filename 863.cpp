class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        std::unordered_map<TreeNode*, std::unordered_set<TreeNode*>>m;
        std::queue<TreeNode*> q({root});
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node -> left){
                m[node].insert(node -> left);
                m[node -> left].insert(node);
                q.push(node -> left);
            }
            if(node -> right){
                m[node].insert(node -> right);
                m[node -> right].insert(node);
                q.push(node -> right);
            }
        }
        q.push(target);
        for(int i=0; i<K; ++i){
            int n = q.size();
            for(int j=0; j<n; ++j){
                TreeNode* node = q.front();
                q.pop();
                for(auto it = m[node].begin(); it != m[node].end();++it){
                    TreeNode* nn = *it;
                    m[nn].erase(node);
                    q.push(nn);
                }
            }
        }
        std::vector<int> res;
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};
