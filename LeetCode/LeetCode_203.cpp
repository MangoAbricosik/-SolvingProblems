class Solution {
public:
    ListNode* findUnique(ListNode* start) {
        int go = start->val;
        while (start && go == start->val) {
            start = start->next;
        }
        return start;
    }

    ListNode* removeElements(ListNode* head, int val) {
        auto curr = head;
        ListNode* prev = NULL;
        while (curr) {
            if (curr->val == val) {
                if (prev && prev->val != val) {
                    prev->next = findUnique(curr);
                    curr = prev;
                }
                else {
                    head = head->next;
                }
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};