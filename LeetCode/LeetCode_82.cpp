class Solution {
public:
    ListNode* findUnique(ListNode* start) {
        int go = start->val;
        while (start && go == start->val) {
            start = start->next;
        }
        return start;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = NULL;
        while (current && current->next) {
            if (current->val == current->next->val) {

                if (prev != NULL) {
                    prev->next = findUnique(current);
                    current = prev;
                }
                else {
                    head = findUnique(current);
                    current = head;
                    prev = NULL;
                    continue;
                }

            }
            prev = current;
            current = current->next;

        }
        return head;
    }
};