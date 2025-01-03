class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        
        unordered_map<int ,int>mp;
        int prefixXor=0 , count=0;
        
        for(int i=0;i<arr.size();i++){
            prefixXor^=arr[i];
            if(prefixXor==k) count++;
            if(mp.find(prefixXor^k)!=mp.end()) count+=mp[prefixXor^k];
            mp[prefixXor]++;
        }
        return count;
    }
};