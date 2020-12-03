class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int res = 0;
        for(Node* child: root -> children) res = std::max(res, maxDepth(child));
         return 1 + res;
    }
};
