class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        if(!head) return NULL;
        Node* current=head;
        while(current){
            Node* clone=new Node(current->data);
            clone->next=current->next;
            current->next=clone;
            current=clone->next;
        }
        
        //find clone random pointer
        current=head;
        while(current){
            Node* clone=current->next;
            if(current->random){
                clone->random=current->random->next;
            }else clone->random=NULL;
            current=clone->next;
        }
        
        //sttep 3 original or clone ko alag kr do
        current=head;
        Node* cloneHead=current->next;
        Node* start=cloneHead;
        
        while(current){
            current->next=current->next->next;
            current=current->next;
            if(current){
                start->next=current->next;
                start=start->next;
            }else start->next=nullptr;
        }
        return cloneHead; 
    }
   
};