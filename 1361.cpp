class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        std::vector<int> in(n,0);
        for(int i = 0; i < n; ++i){
            if(leftChild[i] != -1) ++in[leftChild[i]];
            if(rightChild[i] != -1) ++in[rightChild[i]];
        }
        std::queue<int> q;
        for(int i = 0; i < n; ++i){
             if(in[i] == 0) q.push(i);
             //check two nodes pointing to one node.
            if(in[i] > 1) return false;
        }
        // check multiple roots
        if(q.size() != 1) return false;
        // check loop.
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int left = leftChild[node];
            int right = rightChild[node];
            if(left != -1){
                --in[left];
                if(in[left] == 0) q.push(left);
            }
            if(right != -1){
                --in[right];
                if(in[right] == 0) q.push(right);
            }
        }
        for(const int& d: in){
            if(d != 0) return 0;   
        }
        return true;
       
    }
};

