class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* root = head;
        ListNode* cur = head -> next;
        while(cur && cur -> next){
            ListNode* next_node = cur -> next;
            cur -> next = next_node -> next;
            cur = cur -> next;
            next_node -> next = head -> next;
            head -> next = next_node;
            head = next_node;
        }
        return root;
    }
};
