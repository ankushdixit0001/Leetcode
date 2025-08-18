/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        while (head && head->val == val) {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
        }

        ListNode* curr=head;
        while(curr&&curr->next){
            if(curr->next->val==val){
                ListNode* toDelete=curr->next;
                curr->next=curr->next->next;
                delete toDelete;
            } else {
                curr=curr->next;
            }
        }
        return head;
    }
};