#include <iostream>

using namespace std;

// Function to check if a queen can be placed at row, col
bool isSafe(int board[][100], int row, int col, int n)
{
    // Check if a queen is already placed in the same column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }

    // Check if a queen is already placed in the same diagonal (upper left)
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    // Check if a queen is already placed in the same diagonal (upper right)
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    // If no queen is already placed in the same column or diagonal, it's safe to place a queen
    return true;
}

// Function to print the board
void printBoard(int board[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to solve the n-queens problem using backtracking
void solveNQueens(int n, int board[][100], int row, int &count)
{
    if (row == n)
    {
        // All queens have been placed, increment the count of solutions
        printBoard(board, n);
        count++;
        return;
    }

    // Try to place a queen in each column of the current row
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 1;
            solveNQueens(n, board, row + 1, count);
            board[row][col] = 0; // Backtrack
        }
    }
}

// Main function
int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    // Create an empty board of size n x n
    int board[100][100] = {0};

    // Solve the n-queens problem using backtracking
    int count = 0;
    solveNQueens(n, board, 0, count);

    // Print the number of solutions
    cout << "Number of solutions: " << count << endl;

    return 0;
}