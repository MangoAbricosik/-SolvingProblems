class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        while (current && current->next) {
            if (current->val != current->next->val)
                current = current->next;
            else
                current->next = current->next->next;
        }
        return head;
    }
};