struct cmp{
    bool operator()(ListNode* node1, ListNode* node2){
        return node1 -> val > node2 -> val;
    }  
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>,cmp>pq; 
        for(ListNode* node: lists){
            if(node) pq.push(node);
        }
        ListNode* root = new ListNode(0);
        ListNode* head = root;
        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();
            head -> next = node;
            head = head -> next;
            if(node -> next) pq.push(node -> next);
        }
        return root -> next;
    }
};
