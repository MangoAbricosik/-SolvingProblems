class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;
        int size = 0;
        ListNode* curr = head;
        while (curr) {
            size++;
            curr = curr->next;
        }
        if ((k % size) == 0)
            return head;
        ListNode* dummy = new ListNode(0, head);
        curr = dummy;
        k = k % size;
        for (size_t i = 0; i < (size - k); i++) {
            curr = curr->next;
        }

        ListNode* remains = curr->next;
        ListNode* remainsHead = remains;
        curr->next = nullptr;
        while (remains && remains->next) {
            remains = remains->next;
        }
        remains->next = head;

        return remainsHead;
    }
};