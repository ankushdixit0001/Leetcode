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
    // bool isPalindrome(ListNode* head) {
    //     if(!head) return true;
    //     ListNode* temp=head;
    //     string s;
    //     while(temp){
    //         s.push_back(temp->val);
    //         temp=temp->next;
    //     }
    //     string copyS=s;
    //     reverse(s.begin(),s.end());
    //     return s==copyS;
    // }       
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next) return true;
        //traverse to the middle
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=nullptr;
        while(slow){
            ListNode* nextNode=slow->next;
            slow->next=prev;
            prev=slow;
            slow=nextNode;
        }
        ListNode* left=head;
        ListNode* right=prev;
        while(right){
            if(left->val!=right->val) return false;
            left=left->next;
            right=right->next;
        }
        return true;


    }      
};