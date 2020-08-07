/* 
**  "八皇后问题回溯实现" 
**
**  在8×8格的国际象棋上摆放八个皇后，使其不能互相攻击，即任意两个皇后
**  都不能处于同一行、同一列或同一斜线上，问有多少种摆法。
**
*/

#include <iostream>

#define QUEENSUM 8                              // 自定义几皇后问题

using namespace std;

class Queen {
    public:
        Queen();
        ~Queen() = default;

        void findSolutions();                   // 找到所有的解决方式

    private:
        int solutionsNum;                       // 总共有几种解决方式
        bool arr[QUEENSUM][QUEENSUM];           // 棋盘 => 二维数组

        void setQueen(int row);                 // 放置皇后
        bool isAllow(int row, int col) const;   // 判断是否允许放置
        void printBoard();                      // 打印棋盘

};

Queen::Queen(): solutionsNum(0) {
    // 初始化棋盘全部为false
    for (auto &i : arr)
        for (auto &j : i)     // 因为是二维数组，故要两层循环
            j = false;
}

/* 打印棋盘 */
void Queen::printBoard() {
    ++solutionsNum;
    cout << "-第" << solutionsNum << "种解决方法-" << endl;
    for (auto &i : arr) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/* 判断是否允许放置 */
bool Queen::isAllow(int row, int col) const {
    // 第一行均允许放置
    if (row == 0)
        return true;

    // 1. 判断该列是否能放置Queen
    for (int i = 0; i < row; ++i) {
        if (arr[i][col])
            return false;
    }

    // 2. 判断正斜线是否能放置Queen
    int i = row - 1;
    int j = col - 1;
    while (i >= 0 && j >= 0) {
        if (arr[i--][j--])
            return false;
    }

    // 3. 判断负斜线是否能放置Queen
    i = row - 1;
    j = col + 1;
    while (i >= 0 && j < QUEENSUM) {
        if (arr[i--][j++])
            return false;
    }

    return true;
}

/* 放置皇后 */
void Queen::setQueen(int row) {
    for (int col = 0; col < QUEENSUM; ++col) {
        arr[row][col] = true;
        if (isAllow(row, col)) {
            if(row + 1 == QUEENSUM) {
                printBoard();       // 这是最后一行，并且允许放置，则直接打印棋盘，solutionsNum同时加一
            } else {
                setQueen(row + 1);  // 不是最后一行，则继续递归到下一行
            }
        }
        arr[row][col] = false;      // 无法放置就回溯，并置为false 
    }
}

/* 找到所有的解决方式 */
void Queen::findSolutions() {
    setQueen(0);
    cout << "总共发现" << solutionsNum << "种解决方法" << endl;
}

int main() {
    Queen queen;

    queen.findSolutions();

    return 0;
}