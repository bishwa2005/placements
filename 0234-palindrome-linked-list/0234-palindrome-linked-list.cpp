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
    ListNode* reverse(ListNode* node){
        ListNode* next=NULL;
        ListNode* curr=node;
        ListNode* prev=NULL;

        while(curr){
            next=curr->next;
            curr->next=prev;

            prev=curr;
            curr=next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head==NULL) return false;

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode* rev=reverse(slow);

        while(rev){
            if(head->val != rev->val) return false;
            head=head->next;
            rev=rev->next;
        }

        return true;
    }
};