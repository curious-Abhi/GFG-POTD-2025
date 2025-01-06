class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(),arr.end());
        int s=0,e=arr.size()-1,diff=INT_MAX;
        vector<int>res;
        
        while(s<e){
            int sum=arr[s]+arr[e];
            if(abs(target-sum)<diff){
                diff=abs(target-sum);
                res={arr[s],arr[e]};
            }
            if(sum>target) e--;
            else if(sum<target) s++;
            else return res;
        }
        return res;
        
    }
};

