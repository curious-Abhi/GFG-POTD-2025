class Solution {
    public:
      vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
          // Your code here
          priority_queue<pair<int,vector<int>>>maxHeap;
          
          for(int i=0;i<points.size();i++){
              int d=points[i][0]*points[i][0]+points[i][1]*points[i][1];
              maxHeap.push({d,points[i]});
              if(maxHeap.size()>k) maxHeap.pop();
          }
          vector<vector<int>>result;
          while(!maxHeap.empty()){
              
              result.push_back(maxHeap.top().second);
              maxHeap.pop();
          }
          return result;
          
      }
  };