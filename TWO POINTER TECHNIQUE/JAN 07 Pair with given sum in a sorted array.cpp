class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int s=0,e=arr.size()-1,count=0;
        
        //two pointer 
        while(s<e){
            int sum=arr[s]+arr[e];
            if(sum>target) e--;
            else if(sum<target) s++;
            else {
               int e1=arr[s],e2=arr[e];
               int c1=0,c2=0;
               
               // jb do smae ho 
               while(s<=e && arr[s]==e1){
                   c1++;
                   s++;
               }
               while(s<=e && arr[e]==e2){
                   c2++;
                   e--;
               }
               // saare same 
               if(e1==e2) count+=(c1*(c1-1))/2;
               else count+=c1*c2;
               
            }
        }
        return count;
    }
};