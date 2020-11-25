class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = new ListNode(0);
        pre -> next = head;
        ListNode* root = pre;
        ListNode* slot = head;
        
        while(cur){
            if(slot == cur){
                pre = cur -> next;
                cur = pre;
                if(cur) cur = cur -> next;
                continue;
            }
            ListNode* node = cur;
            pre -> next = cur -> next;
            pre = pre -> next;
            cur = pre;
            if(cur) cur = cur -> next;
    
            node -> next = slot -> next;
            slot -> next = node;
            slot = node;
        }
        return root -> next;
    }
};
