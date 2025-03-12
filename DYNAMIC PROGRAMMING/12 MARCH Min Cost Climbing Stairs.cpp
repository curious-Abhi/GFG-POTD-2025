class Solution {
    public:
      int minCostClimbingStairs(vector<int>& cost) {
          // Write your code here
          int n=cost.size();
          for(int i=2;i<n;i++){
              cost[i]+=min(cost[i-2],cost[i-1]);
          }
          return min(cost[n-2],cost[n-1]);
      }
  };