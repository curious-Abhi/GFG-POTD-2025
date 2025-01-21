/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(!head) return head;
        Node *prev=NULL, *curr=head, *next=curr->next;
        int count =0;
        while(curr && count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
       if(next!=nullptr) head->next= reverseKGroup(next,k);
        return prev;
    }
};
