#include <bits/stdc++.h>

using namespace std;

// Function Prototypes
void print_board(int board[9][9]);
bool is_valid(int board[9][9], int pos[2], int val);
void find_empty_spot(int board[9][9], int pos[2]);
bool solve(int board[9][9]);


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int board[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                       {6, 0, 0, 1, 9, 5, 0, 0, 0},
                       {0, 9, 8, 0, 0, 0, 0, 6, 0},
                       {8, 0, 0, 0, 6, 0, 0, 0, 3},
                       {4, 0, 0, 8, 0, 3, 0, 0, 1},
                       {7, 0, 0, 0, 2, 0, 0, 0, 6},
                       {0, 6, 0, 0, 0, 0, 2, 8, 0},
                       {0, 0, 0, 4, 1, 9, 0, 0, 5},
                       {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    print_board(board);
    solve(board);
    cout << endl;
    print_board(board);

    return 0;
}

// Display the board in the console
void print_board(int board[9][9]) {
    for(int i = 0; i < 9; i++) {
        for(int k = 0; k < 9; k++) {
            cout << board[i][k] << " ";
        }
        cout << endl;
    }
}

// Find an empty spot that does not have a value yet
void find_empty_spot(int board[9][9], int pos[2]) {
    for(int i = 0; i < 9; i++) {
        for(int k = 0; k < 9; k++) {
            if(board[i][k] == 0) {
                pos[0] = i;
                pos[1] = k;
                return;
            }
        }
    }
}

// Check if adding the value follows rules of sudoku
bool is_valid(int board[9][9], int pos[2], int val) {
    //Check horizontal
    for(int i = 0; i < 9; i++) {
        if(board[pos[0]][i] == val) {
            return false;
        }
    }

    //Check vertical
    for(int i = 0; i < 9; i++) {
        if(board[i][pos[1]] == val) {
            return false;
        }
    }

    //Check box
    int box_row = (int)(pos[0] / 3) * 3;
    int box_col = (int)(pos[1] / 3) * 3;

    for(int row = box_row; row < box_row + 3; row++) {
        for(int col = box_col; col < box_col + 3; col++) {
            if(board[row][col] == val) {
                return false;
            }
        }
    }

    return true;
}


// Solving the puzzle
bool solve(int board[9][9]) {
    int pos[2] = {-1, -1};

    find_empty_spot(board, pos);

    // No more empty spots left
    if (pos[0] == -1) {
        return true;
    }

    for(int x = 1; x < 10; x++) {
        if (is_valid(board, pos, x)) {
            board[pos[0]][pos[1]] = x;
            if (solve(board)) {
                return true;
            } else {
                board[pos[0]][pos[1]] = 0;
            }
        } 
    }
    
    // Cannot solve
    return false;
}