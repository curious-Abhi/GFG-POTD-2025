class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int s=0,sum=0;
        for(int e=0;e<arr.size();e++){
            sum+=arr[e];
            // if(sum<target ) e++
            // if(sum>target)
            
            while(sum>target  && s<=e){
                sum-=arr[s];
                s++;
            }
            if(sum==target) return {s+1,e+1};
        }
        return {-1};
    }
};