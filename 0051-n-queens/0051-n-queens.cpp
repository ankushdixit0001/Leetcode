class Solution {
public:
    bool issafe(vector<string>& board, int row, int col) {
        int n = board.size();
        // horizontal
        for (int j = 0; j < n; j++) {
            if (board[row][j] == 'Q') {
                return false;
            }
        }
        // vertical
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        // diagonal left
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        // diagonal right
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void nQueens(vector<string>& board, int row, vector<vector<string>>& res) {
        int n = board.size();
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (issafe(board, row, j)) {
                board[row][j] = 'Q';
                nQueens(board, row + 1, res);
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;
        nQueens(board, 0, res);
        return res;
    }
};