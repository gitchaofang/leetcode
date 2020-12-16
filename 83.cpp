class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* root =  new ListNode(0);
        root -> next = head;
        while(head){
            ListNode* node = head;
            while(node && node -> val == head -> val) node  = node -> next;
            head -> next = node;
            head = node;
        }
        return root -> next;
    }
};
