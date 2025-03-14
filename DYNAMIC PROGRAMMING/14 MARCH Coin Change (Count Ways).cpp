class Solution {
    public:
    int dp[1001][1001];
    int solve(vector<int>& coins, int sum,int i){
        //base case 
        if(sum<0) return 0;
        if(sum==0) return 1;
        
        if(i==coins.size()) return 0;
        //recursive case 
        if(dp[i][sum]!=-1) return dp[i][sum];
        int makeSum=solve(coins,sum-coins[i],i);
        int notMakeSum=solve(coins,sum,i+1);
        return dp[i][sum]=makeSum+notMakeSum;
    }
      int count(vector<int>& coins, int sum) {
          // code here.
          memset(dp,-1,sizeof(dp));
          return solve(coins,sum,0);
      }
  };