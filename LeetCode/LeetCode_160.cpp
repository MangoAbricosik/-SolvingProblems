class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        set<ListNode*> st;
        while (headA) {
            st.insert(headA);
            headA = headA->next;
        }

        while (headB) {
            if (!st.insert(headB).second) {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};