class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string str;
        while (head) {
            str += head->val + '0';
            head = head->next;
        }

        auto l = str.begin();
        auto r = str.end() - 1;

        while (l <= r) {
            if (*l != *r)
                return false;
            l++;
            r--;
        }
        return true;
    }
};