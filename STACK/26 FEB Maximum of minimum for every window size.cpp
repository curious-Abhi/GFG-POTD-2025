class Solution {
    public:
        vector<int> maxOfMins(vector<int>& arr) {
            int n = arr.size();
            vector<int> left(n, -1), right(n, n), ans(n + 1, 0);
            stack<int> st;
    
            for (int i = 0; i < n; i++) {
                while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
                if (!st.empty()) left[i] = st.top();
                st.push(i);
            }
    
            while (!st.empty()) st.pop();
    
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
                if (!st.empty()) right[i] = st.top();
                st.push(i);
            }
    
            for (int i = 0; i < n; i++) 
                ans[right[i] - left[i] - 1] = max(ans[right[i] - left[i] - 1], arr[i]);
    
            for (int i = n - 1; i >= 1; i--) 
                ans[i] = max(ans[i], ans[i + 1]);
    
            return vector<int>(ans.begin() + 1, ans.end());
        }
    };
    