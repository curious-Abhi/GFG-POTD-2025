class Solution {
public:
    bool isSafe(vector<vector<int>>& mat, int row, int col, int num) {
        for (int i = 0; i < 9; i++) 
            if (mat[row][i] == num || mat[i][col] == num) return false;
        
        int startRow = row - row % 3, startCol = col - col % 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (mat[startRow + i][startCol + j] == num) return false;
        
        return true;
    }

    bool solve(vector<vector<int>>& mat) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (mat[row][col] == 0) {
                    for (int num = 1; num <= 9; num++) {
                        if (isSafe(mat, row, col, num)) {
                            mat[row][col] = num;
                            if (solve(mat)) return true;
                            mat[row][col] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<int>>& mat) {
        solve(mat);
    }
};
