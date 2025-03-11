/****************************Recursive approach   *********************************


class Solution {
  public:
    int solve(int n){
    //base case 
    if(n<=2) return n;
    //recursive case 
    return solve(n-2)+solve(n-1);
    }
    int countWays(int n) {
        // your code here
        return solve(n);
    }
 */


/*   Top down approach

class Solution {
  public:
    int dp[45];
    int solve(int n){
    //base case 
    if(n<=2) return n;
    //recursive case 
    if(dp[n]!=-1) return dp[n];
    return dp[n]=solve(n-2)+solve(n-1);
    }
    int countWays(int n) {
        // your code here
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};


*/

/***********Bottom up Approach**********************************
 class Solution {
  public:
    int dp[45];
    int solve(int n){
      dp[0]=0;
      dp[1]=1;
      dp[2]=2;
      for(int i=3;i<=n;i++){
          dp[n]=solve(n-1)+solve(n-2);
      }
      return dp[n];
    }
    int countWays(int n) {
        // your code here
        return solve(n);
    }
};

 */



 //Optimized approach   using two variable 

 class Solution {
  public:
    int solve(int n){
      int prev1=1;
      int prev2=1;
      int curr;
      
      if(n<=1) return n;
      for(int i=2;i<=n;i++){
          curr=prev1+prev2;
          prev1=prev2;
          prev2=curr;
      }
      return prev2;
    }
    int countWays(int n) {
        // your code here
        return solve(n);
    }
};
