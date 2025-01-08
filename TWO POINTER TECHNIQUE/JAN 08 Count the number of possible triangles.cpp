class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        
        sort(arr.begin(),arr.end());
        int count=0;
        for(int k=arr.size()-1;k>=2;k--){
            int i=0,j=k-1;
            //two pointer approach
            while(i<j){
                if(arr[i]+arr[j]>arr[k]){
                    count+=j-i;
                    j--;
                }else {
                    i++;
                }
            }
        }
        return count;
    }
};