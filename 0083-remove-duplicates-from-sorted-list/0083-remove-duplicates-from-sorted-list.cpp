class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* temp = head;
        while (temp && temp->next) {
            if (temp->val == temp->next->val) {
                // Skip all nodes with the same value
                ListNode* dup = temp->next;
                while (dup && dup->val == temp->val) {
                    dup = dup->next;
                }
                temp->next = dup;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};