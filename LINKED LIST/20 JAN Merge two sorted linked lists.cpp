class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node* start=new Node(-1);
        Node* temp=start;
        
        while(head1!=nullptr && head2!=nullptr){
            if(head1->data < head2->data){
                temp->next=head1;
                head1=head1->next;
            } else {
                temp->next=head2;
                head2=head2->next;
            }
            temp=temp->next;
            
        }
        if(head1!=nullptr) temp->next=head1;
        if(head2!=nullptr) temp->next=head2;
        
        return start->next;
    }
};


/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/



/*
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        // Node* start=new Node(-1);
        //Node* temp=start;
      
        
        Node *newHead=nullptr;
         Node* temp=newHead;
        if(head1->data<head2->data){
            newHead=head1;
            head1=newHead->next;
        }else {
            newHead=head2;
            head2=newHead->next;
        }
        temp=newHead;
        
        while(head1!=nullptr && head2!=nullptr){
            if(head1->data < head2->data){
                temp->next=head1;
                head1=head1->next;
            } else {
                temp->next=head2;
                head2=head2->next;
            }
            temp=temp->next;
            
        }
        if(head1!=nullptr) temp->next=head1;
        if(head2!=nullptr) temp->next=head2;
        
        // return start->next;
        return newHead;
    }
};
*/
