#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, const vector<string>& board, int n) {
    // 1. Upper-left diagonal
    for (int r = row, c = col; r >= 0 && c >= 0; r--, c--) {
        if (board[r][c] == 'Q') return false;
    }

    // 2. Left row
    for (int c = col; c >= 0; c--) {
        if (board[row][c] == 'Q') return false;
    }

    // 3. Lower-left diagonal
    for (int r = row, c = col; r < n && c >= 0; r++, c--) {
        if (board[r][c] == 'Q') return false;
    }

    return true;
}

void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
    if (col == n) {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++) {
        if (isSafe(row,col,board,n)) {
            board[row][col] = 'Q';
            solve(col+1, board, ans, n);
            board[row][col] = '.';
        }
    }
}
