class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        
        int n=arr.size();
        vector<int>res(n,1);
        
        int left_product=1;
        for(int i=0;i<n;i++){
            res[i]=left_product;
            left_product*=arr[i];
        }
        
        int right_product=1;
        for(int i=n-1;i>=0;i--){
            res[i]*=right_product;
            right_product*=arr[i];
            
        }
        return res;
    }
};

/*

// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>res(n,1);
        int product=1,zeroCount=0;
        
        for(int num:arr){
            if(num!=0) product*=num;
            else zeroCount++;
        }
        
        for(int i=0;i<n;i++){
            if(zeroCount>1) res[i]=0;
            else if(zeroCount==1) res[i]=(arr[i]==0)?product:0;
            else res[i]=product/arr[i];
        }
        return res;
    }
};
*/