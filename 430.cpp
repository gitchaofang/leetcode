class Solution {
public:
    Node* dfs(Node* root){
        if(!root -> next && !root -> child) return root;
        Node* tail = root;
        Node* nt = root -> next;
        if(root -> child){
            Node* child_tail = dfs(root -> child);
            tail -> next = root -> child;
            root -> child -> prev = root;
            root -> child = nullptr;
            tail = child_tail;
        }
        if(nt){
            Node* nt_tail = dfs(nt);
            tail -> next = nt;
            nt -> prev = tail;
            tail = nt_tail;
        }
        return tail;
    }
    Node* flatten(Node* head) {
        if(!head) return nullptr;
        dfs(head);
        return head;
    }
};
