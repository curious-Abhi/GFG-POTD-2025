class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        
        int area=0,l=0,r=arr.size()-1;
        while(l<r){
            int h=min(arr[l],arr[r]);
            int w=r-l;
            area=max(area,h*w);
            
            if(arr[l]<arr[r]) l++;
            else r--;
        }
        return area;
    }
};