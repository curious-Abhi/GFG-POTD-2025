class Solution {
    public:
      vector<int> calculateSpan(vector<int>& arr) {
          // write code here
          stack<int>st;
          vector<int>ans;
          
          for(int i=0;i<arr.size();i++){
              while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
              if(st.empty()) ans.push_back(i+1);
              else  ans.push_back(i-st.top());
              st.push(i);
          }
          return ans;
      }
  };