class Solution {
  public:
    double power(double b, int e) {
        // code here
        //return pow(b,e);
        
        if(e==0)  return 1;
        if(e<0) return power(1/b,-e);
        double half=power(b,e/2);
        return (e%2==0)?half*half:half*half*b;
    }
};