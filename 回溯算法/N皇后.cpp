#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n, string(n,'.'));
        backtracking(chessboard, 0, n);
        return result;
    }
    vector<vector<string>> result;
    void backtracking(vector<string> &chessboard, int row, int n) {
        if (row == n) {
            result.push_back(chessboard);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(chessboard, row, i, n)) {
                chessboard[row][i] = 'Q';
                backtracking(chessboard, row + 1, n);
                chessboard[row][i] = '.';
            }
        }
    }
    bool isValid(vector<string> &chessboard, int row, int col, int n) {
        // 行无须进行检查
        for (int j = 0; j != row && j < n; j++) {
            if (chessboard[j][col] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--,j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--,j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};