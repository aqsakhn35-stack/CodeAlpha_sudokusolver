#include <iostream>
using namespace std;

bool isSafe(int grid[9][9], int row, int col, int num)
{
    // Row check
    for(int x = 0; x < 9; x++)
    {
        if(grid[row][x] == num)
            return false;
    }

    // Column check
    for(int x = 0; x < 9; x++)
    {
        if(grid[x][col] == num)
            return false;
    }

    // 3x3 Box check
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(grid[i + startRow][j + startCol] == num)
                return false;
        }
    }

    return true;
}

bool solveSudoku(int grid[9][9])
{
    int row, col;
    bool empty = false;

    for(row = 0; row < 9; row++)
    {
        for(col = 0; col < 9; col++)
        {
            if(grid[row][col] == 0)
            {
                empty = true;
                break;
            }
        }
        if(empty)
            break;
    }

    if(!empty)
        return true;

    for(int num = 1; num <= 9; num++)
    {
        if(isSafe(grid, row, col, num))
        {
            grid[row][col] = num;

            if(solveSudoku(grid))
                return true;

            grid[row][col] = 0;
        }
    }

    return false;
}

void printGrid(int grid[9][9])
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int grid[9][9] =
    {
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };

    cout << "Original Sudoku:\n\n";
    printGrid(grid);

    if(solveSudoku(grid))
    {
        cout << "\nSolved Sudoku:\n\n";
        printGrid(grid);
    }
    else
    {
        cout << "No Solution Exists!";
    }

    return 0;
}
