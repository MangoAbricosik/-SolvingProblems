class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int size = 0;
        auto curr = head;
        while (curr) {
            size++;
            curr = curr->next;
        }
        curr = head;
        for (size_t i = 0; i < (size / 2); i++) {
            curr = curr->next;
        }
        head = curr;
        return head;
    }
};