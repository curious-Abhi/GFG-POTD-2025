class Solution {
    public:
    int dp[1001][1001];
    
    int solve(int i ,int j,string &s,string &rev){
        //base case 
        if(i==s.size()|| j==rev.size()) return 0;
        
        //recursive case
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==rev[j]) return dp[i][j]=1+solve(i+1,j+1,s,rev);
        else return dp[i][j]=max(solve(i,j+1,s,rev),solve(i+1,j,s,rev));
        
    }
      int longestPalinSubseq(string &s) {
          // code here
          string rev=s;
          reverse(rev.begin(),rev.end());
          memset(dp,-1,sizeof(dp));
          return solve(0,0,s,rev);
      }
  };