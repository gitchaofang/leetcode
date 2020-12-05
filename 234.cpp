class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode* root = head;
        ListNode* node = new ListNode(head -> val);
        ListNode* pre = nullptr;
        while(node){
            ListNode* next = new ListNode();
            if(head -> next) next -> val = head -> next -> val;
            else next = nullptr;
            head = head -> next;
            node -> next = pre;
            pre = node;
            node = next;
        }
        while(root){
            if(root -> val != pre -> val) return false;
            root = root -> next;
            pre = pre -> next;
        }
        return true;
    }
};
