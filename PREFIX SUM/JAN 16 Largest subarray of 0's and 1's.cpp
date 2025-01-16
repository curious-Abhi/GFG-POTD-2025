class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        int sum=0,l=0;
        unordered_map<int,int>mp;
        
        for(int i=0;i<arr.size();i++){
            sum+=(arr[i]==0)?-1:1;  
            if(sum==0) l=max(l,i+1);
            
            if(mp.find(sum)!=mp.end()) l=max(l,i-mp[sum-0]);
            else mp[sum]=i;
        }
        return l;
        
    }
};