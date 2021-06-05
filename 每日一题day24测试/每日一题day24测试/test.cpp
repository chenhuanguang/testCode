#include <iostream>
#include <vector>
using namespace std;

int maxGifts(vector<vector<int> > board, int i, int j)
{
    if (i == 0 && j == 0)
        return board[0][0];
    if (i == 0)
        return maxGifts(board, i, j - 1) + board[i][j];
    if (j == 0)
        return maxGifts(board, i - 1, j) + board[i][j];
    return max(maxGifts(board, i, j - 1), maxGifts(board, i - 1, j)) + board[i][j];
}

int getMost(vector<vector<int>> board) {
    return maxGifts(board, 3, 3);
}

int main()
{
    vector<vector<int>> board{ {1,2,3},{4,5,6},{7,8,9} };
    getMost(board);
    return 0;
}