/*
class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
*/
class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        Node* tail = new Node(x);
        Node* temp = head;
        if (temp==NULL) return tail;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=tail;

        return head;
    }
};