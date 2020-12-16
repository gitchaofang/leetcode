class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* nt = head;
        while(nt && nt -> next){
            head = head -> next;
            nt = nt -> next;
            if(nt) nt = nt -> next;
        }
        return head;
    }
};
