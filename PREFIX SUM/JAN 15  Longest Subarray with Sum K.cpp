class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int sum=0,l=0;
        unordered_map<int,int>mp;
        
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==k) l=max(l,i+1);
            if(mp.find(sum)==mp.end())  mp[sum]=i;
            
            if(mp.find(sum-k)!=mp.end()) l=max(l,i-mp[sum-k]);
        }
        return l;
        
    }
};