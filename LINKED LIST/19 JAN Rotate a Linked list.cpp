/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // Your code here
        
        if(!head)  return head;
        int l=1;
        Node *temp=head;
        while(temp->next){
            temp=temp->next;
            l++;
        }
        
        k=k%l;
        if(k==0) return head;
        
        //rotate k times
        temp->next=head;
        temp=head;
        for(int i=1;i<k;i++){
            temp=temp->next;
        }
        Node *newHead=temp->next;
        temp->next=NULL;
        
        return newHead;
    }
};