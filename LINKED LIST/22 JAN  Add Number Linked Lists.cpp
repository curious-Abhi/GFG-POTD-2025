class Solution {
  public:
  
    Node* reverse(Node* head){
        Node *prev=NULL, *curr=head,*next=curr->next;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        num1= reverse(num1);
        num2= reverse(num2);
        int carry=0;
        Node* ans=new Node(0);
        Node* start=ans;
        
        while(num1 || num2 || carry){
            int sum=carry;
            if(num1){
                sum+=num1->data;
                num1=num1->next;
            }
            if(num2){
                sum+=num2->data;
                num2=num2->next;
            }
            ans->data=sum%10;
            carry=sum/10;
            
            if(num1 || num2 || carry){
                ans->next=new Node(0);
                ans=ans->next;
            }
           
        }
            reverse(start);
            
            while(ans->data==0 && ans->next) ans=ans->next;
            return ans;
    }
};
