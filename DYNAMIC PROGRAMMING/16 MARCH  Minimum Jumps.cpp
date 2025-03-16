class Solution {
    public:
      int minJumps(vector<int>& arr) {
          // code here
          int n=arr.size();
          
          if(n==1) return 0;
          if(arr[0]==0) return -1;
          
          
          int boundary=arr[0];
          int max_length=arr[0];
          int jump=1;
          
  
          
          for(int i=1;i<n;i++){
              if(i==n-1) return jump;
              
              max_length=max(max_length,i+arr[i]);
              
              if(i==boundary) {
                  jump++;
                  boundary=max_length;
                  if(max_length<=i) return -1;
              }
          }
          return -1;
      }
  };
  