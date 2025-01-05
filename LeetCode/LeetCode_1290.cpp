class Solution {
public:
    int getDecimalValue(ListNode* head) {
        if (head->next == nullptr)
            return head->val;

        int size = 0, ans = 0;
        ListNode* curr = head;
        while (curr) {
            size++;
            curr = curr->next;
        }

        curr = head;
        for (size_t i = size - 1; i != -1; i--) {
            if (curr->val != 0)
                ans += pow(2, i);
            curr = curr->next;
        }
        return ans;
    }
};