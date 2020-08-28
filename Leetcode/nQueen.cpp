/**
 *  51. N皇后
 * 
 * `n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，
 *  并且使皇后彼此之间不能相互攻击。
 * 
 *  给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 *  每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 
 *  分别代表了皇后和空位。
 * 
 *  来源：力扣（LeetCode）
 *  链接：https://leetcode-cn.com/problems/n-queens
 *  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> board;
    vector<vector<string>> allBoard;
    int queenNum;

    void printBoard() {
        for(auto i : board) {
            cout << i << endl;
        }
        cout << "~~~~" << endl;
    }

    bool isAllow(int row, int col) const {
        // 1. 第一行均可以放置
        if(row == 0) {
            return true;
        }

        // 2. 判断该列是否可以放置
        for(int i = 0; i < row; ++i) {
            if(board[i][col] == 'Q')
                return false;
        }

        // 3. 判断正斜线是否能放置
        int i = row - 1;
        int j = col - 1;
        while(i >= 0 && j >= 0) {
            if(board[i--][j--] == 'Q') 
                return false;
        }

        // 4. 判断负斜线是否能放置
        i = row - 1;
        j = col + 1;
        while(i >= 0 && j < queenNum) {
            if(board[i--][j++] == 'Q')
                return false;
        }

        return true;
    }

    void setQueen(int row) {
        for(int col = 0; col < queenNum; ++col) {
            board[row][col] = 'Q';
            if(isAllow(row, col)) {
                if(row + 1 == queenNum) {
                    // 这是最后一行，并且允许放置，则将该棋盘添加到解决方法合集allBoard中
                    allBoard.emplace_back(board);
                } else {
                    // 不是最后一行，则继续递归到下一行
                    setQueen(row + 1);
                }
            }
            // 无法放置就回溯，并置为'.'
            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {    
        queenNum = n;

        // 初始化棋盘board
        for(int i = 0; i < n; ++i) {
            string rowBorad(n, '.');
            board.emplace_back(rowBorad);
        }
        
        // 从第一行开始放置Queen
        setQueen(0);

        return allBoard;
    }
};


int main() {
    Solution way1;
    vector<vector<string>> all = way1.solveNQueens(4);

    for(auto &i : all) {
        for(auto &j : i) {
            cout << j << endl;
        }
        cout << "----" << endl;
    }

    return 0;
}