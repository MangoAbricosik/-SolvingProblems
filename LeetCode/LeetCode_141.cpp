class Solution {
public:
    bool hasCycle(ListNode* head) {
        set<ListNode*> st;
        auto curr = head;
        while (curr) {
            if (st.insert(curr).second) {
                curr = curr->next;
            }
            else
                return true;
        }
        return false;
    }
};