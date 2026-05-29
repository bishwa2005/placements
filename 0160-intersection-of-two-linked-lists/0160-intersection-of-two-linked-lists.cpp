/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int len(ListNode* head){
        int n=0;
        while(head){
            n++;
            head=head->next;
        }
        return n;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=len(headA);
        int l2=len(headB);

        while(l1>l2){
            headA=headA->next;
            l1--;
        }
        while(l2>l1){
            headB=headB->next;
            l2--;
        }

        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }

        return headA;

        
    }
};