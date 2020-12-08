class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        std::unordered_set<int>st(G.begin(), G.end());
        int res = 0;
        int pre = 0;
        while(head){
            int d = head -> val;
            if(st.find(d) == st.end()){ 
                res += (pre == 1);
                pre = 0;
            }
            else pre = true;
            head = head -> next;
        }
        if(pre == 1) ++res;
        return res;
    }
};
