class Solution {
public:
    ListNode* rev(ListNode* head){
        if(!head -> next) return head;
        ListNode* root = rev(head -> next);
        head -> next -> next = head;
        head -> next = nullptr;
        return root;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        return rev(head);
    }
};
