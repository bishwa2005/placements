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
        ListNode* temp = head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        return n;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=len(headA);
        int len2=len(headB);

        while(len1>len2){
            headA=headA->next;
            len1--;
        }

        while(len1<len2){
            headB=headB->next;
            len2--;
        }

        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }

        return headA;

    }
};