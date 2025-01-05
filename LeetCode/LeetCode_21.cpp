class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(0);
        auto dummy = ans;
        while (list2 || list1) {
            int first = list1 ? list1->val : INT_MAX;
            int second = list2 ? list2->val : INT_MAX;

            if (first <= second) {
                ans->next = list1;
                list1 = list1->next;
            }
            else {
                ans->next = list2;
                list2 = list2->next;
            }
            ans = ans->next;
        }
        dummy = dummy->next;
        return dummy;
    }
};