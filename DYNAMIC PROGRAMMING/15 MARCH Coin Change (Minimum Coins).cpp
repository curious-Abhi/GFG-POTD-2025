class Solution {
    public:
      int minCoins(vector<int> &coins, int sum) {
          // code here
           vector<int> dp(sum + 1, 1e9); 
           dp[0] = 0;
  
          for (int coin : coins) {
              for (int s = coin; s <= sum; s++) {
                  dp[s] = min(dp[s], 1 + dp[s - coin]);
              }
          }
  
          return (dp[sum] >= 1e9) ? -1 : dp[sum];
      }
  };