class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* result = new ListNode(0);
        ListNode* curr = result;
        vector<ListNode*> arr;
        while (head) {
            arr.push_back(head);
            head = head->next;
        }

        reverse(arr.begin(), arr.end());
        for (auto item : arr) {
            curr->next = item;
            curr = curr->next;
        }
        curr->next = nullptr;

        auto temp = result;
        result = result->next;
        delete temp;
        return result;
    }
};