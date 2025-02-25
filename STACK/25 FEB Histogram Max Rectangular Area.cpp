class Solution {
    public:
      int getMaxArea(vector<int> &arr) {
          // Your code here
          int n=arr.size();
          int maxA=0;
          stack<int>st;
          
          for(int i=0;i<=n;i++){
              int h=(i==n)?0:arr[i];
              
              while(!st.empty() && h<arr[st.top()]){
                  int tIndex=st.top();
                  st.pop();
                  int width=st.empty()?i:i-st.top()-1;
                  int area=arr[tIndex]*width;
                  maxA=max(area,maxA);
              }
              st.push(i);
          }
          return maxA;
      }
  };