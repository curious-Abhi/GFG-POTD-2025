class Solution {
    public:
      vector<int> kLargest(vector<int>& arr, int k) {
          // Your code here
          priority_queue<int, vector<int> , greater<int>>mh(arr.begin(),arr.begin()+k);
          for(int i=k;i<arr.size();i++) 
            if(arr[i]>mh.top()) mh.pop(), mh.push(arr[i]);
          
          //for  return output 
          vector<int>r(k);
          while(!mh.empty()) r[--k]=mh.top(),mh.pop();
          
          return r;
          
      }
  };