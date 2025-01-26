class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        
        //detect loop
        if(!head || !head->next) return;
        Node *slow=head, *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        if(slow!=fast) return;  //loop not found 
        
        //finding starting point 
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        while(fast->next!=slow){
            fast=fast->next;
        }
        fast->next=NULL;
    }
};