class Solution {
    public:
      vector<int> longestSubarray(vector<int>& arr, int x) {
          // code here
          int n = arr.size(), l = 0, bestL = 0, bestLen = 0;
          deque<int> maxDq, minDq;
          for (int r = 0; r < n; r++) {
              while (!maxDq.empty() && arr[maxDq.back()] < arr[r]) maxDq.pop_back();
              maxDq.push_back(r);
              
              while (!minDq.empty() && arr[minDq.back()] > arr[r]) minDq.pop_back();
              minDq.push_back(r);
              
              while (arr[maxDq.front()] - arr[minDq.front()] > x) {
                  if (maxDq.front() == l) maxDq.pop_front();
                  if (minDq.front() == l) minDq.pop_front();
                  l++;
              }
              
              if (r - l + 1 > bestLen) { bestLen = r - l + 1; bestL = l; }
          }
          
          return vector<int>(arr.begin() + bestL, arr.begin() + bestL + bestLen);
      }
  };