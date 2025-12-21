#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n) {
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }
    // Check left upper diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
    // Check right upper diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }
    return true;
}

void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans) {
    if (row == n) {
        ans.push_back(board);
        return;
    }
    for (int j = 0; j < n; j++) {
        if (isSafe(board, row, j, n)) {
            board[row][j] = 'Q';
            nQueens(board, row + 1, n, ans);
            board[row][j] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    nQueens(board, 0, n, ans);
    return ans;
}

// Function to pretty-print a board with grid lines
void printBoard(const vector<string> &board) {
    int n = board.size();
    string line = "+";
    for (int i = 0; i < n; i++) line += "---+";
    cout << line << "\n";

    for (int i = 0; i < n; i++) {
        cout << "|";
        for (int j = 0; j < n; j++) {
            cout << " " << board[i][j] << " |";
        }
        cout << "\n" << line << "\n";
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<string>> solutions = solveNQueens(n);

    cout << "Total solutions: " << solutions.size() << "\n\n";
    int count = 1;
    for (auto &sol : solutions) {
        cout << "Solution #" << count++ << ":\n";
        printBoard(sol);
        cout << "\n";
    }
    return 0;
}
