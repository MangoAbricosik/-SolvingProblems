class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy(0);
        ListNode pummy(0);
        ListNode* pDummy = &dummy;
        ListNode* pPummy = &pummy;
        auto* save = head;
        while (head) {
            if (head->val < x) {
                pDummy->next = head;
                pDummy = head;
            }
            else {
                pPummy->next = head;
                pPummy = head;
            }
            head = head->next;
        }

        pPummy->next = nullptr;
        pDummy->next = pummy.next;


        return dummy.next;
    }
};