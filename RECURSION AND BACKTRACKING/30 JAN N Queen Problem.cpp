class Solution {
  public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> res;
        vector<int> board(n, -1);
        solve(0, board, res, n);
        return res;
    }       

    void solve(int col, vector<int>& board, vector<vector<int>>& res, int n) {
        if (col == n) {
            vector<int> solution;
            for (int row : board) {
                solution.push_back(row + 1);
            }
            res.push_back(solution);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board)) {
                board[col] = row;
                solve(col + 1, board, res, n);
                board[col] = -1; // Backtrack
            }
        }
    }
    
    bool isSafe(int row, int col, vector<int>& board) {
        for (int i = 0; i < col; i++) {
            if (board[i] == row || abs(board[i] - row) == abs(i - col)) 
                return false;
        }
        return true;
    }
};
