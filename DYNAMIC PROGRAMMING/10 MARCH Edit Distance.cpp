class Solution {
    public:
    int dp[1001][1001];
      // Function to compute the edit distance between two strings
      int solve(string& s1, string& s2,int i,int j){
          
          //base case 
          if(i==s1.size()) return s2.length()-j;
          if(j==s2.size()) return s1.length()-i;
          
          //recursive case 
          if(dp[i][j]!=-1) return dp[i][j];
          if(s1[i]==s2[j]) return dp[i][j]=solve(s1,s2,i+1,j+1);
          else {
              int insert=1+solve(s1,s2,i,j+1);
              int delet=1+solve(s1,s2,i+1,j);
              int replace =1+solve(s1,s2,i+1,j+1);
              return  dp[i][j]=min({insert,delet,replace});
          }
         
      }
      int editDistance(string& s1, string& s2) {
          // code here
          memset(dp,-1,sizeof(dp));
          return solve(s1,s2,0,0);
      }
  }