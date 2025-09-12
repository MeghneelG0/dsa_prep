#include <iostream>
#include <vector>

// Helper function to check if a number can be placed at a given position
bool isSafe(std::vector<std::vector<char>>& board, int row, int col, char num) {
    // Check the current row
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }

    // Check the current column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }

    // Check the current 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Main recursive backtracking function to solve the Sudoku puzzle
bool solveSudoku(std::vector<std::vector<char>>& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            // Find an empty cell
            if (board[row][col] == '.') {
                // Try placing numbers '1' through '9'
                for (char num = '1'; num <= '9'; num++) {
                    if (isSafe(board, row, col, num)) {
                        // Place the number and recurse
                        board[row][col] = num;

                        // If the recursive call finds a solution, we're done
                        if (solveSudoku(board)) {
                            return true;
                        }

                        // Backtrack: undo the choice if it didn't lead to a solution
                        board[row][col] = '.';
                    }
                }
                // If no number from 1-9 works, this path is wrong, trigger backtracking
                return false;
            }
        }
    }
    // If there are no empty cells left, the puzzle is solved
    return true;
}

int main() {
    // Initialize the Sudoku board
    std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    if (solveSudoku(board)) {
        std::cout << "Sudoku Solved Successfully:" << std::endl;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "No solution exists for the given Sudoku." << std::endl;
    }

    return 0;
}