class Solution {
    public:
     int dp[1001][1001];
     int solve(int W, vector<int> &val, vector<int> &wt,int i){
         //base case 
         if(i==wt.size()) return 0;
         //recursive case 
         if(dp[i][W]!=-1) return dp[i][W];
          int pack=0;
          if(W>=wt[i])  pack=val[i]+solve(W-wt[i],val,wt,i+1);
          int noPack=solve(W,val,wt,i+1);
          return dp[i][W]=max(pack,noPack);
         
     }
    
      int knapsack(int W, vector<int> &val, vector<int> &wt) {
          // code here
          memset(dp,-1,sizeof(dp));
          return solve(W,val,wt,0);
      }
  };