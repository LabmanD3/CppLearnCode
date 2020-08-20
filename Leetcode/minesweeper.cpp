/*
**  529. 扫雷游戏 (Minesweeper)
**
**  让我们一起来玩扫雷游戏！
**
**  给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，
**  'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，
**  数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X' 则表示一个已挖出的地雷。
**
**  现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），
**  根据以下规则，返回相应位置被点击后对应的面板：
**
**      1. 如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。
**      2. 如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），
**         并且所有和其相邻的未挖出方块都应该被递归地揭露。
**      3. 如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），
**         表示相邻地雷的数量。
**      4. 如果在此次点击中，若无更多方块可被揭露，则返回面板。
**
**  来源：力扣（LeetCode）
**  链接：https://leetcode-cn.com/problems/minesweeper
**  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        // int width, length;
        // width = board.size();
        // length = board[0].size();

        // if((length < 1 && length > 50) && (length < 1 && length > 50))
        //     return board;

        int x = click[0], y = click[1];
        if(board[x][y] == 'M') {
            /* 规则 1，踩雷，游戏结束 */
            board[x][y] = 'X';
            return board;
        } else {
            dfs(board, x, y);
            return board;
        }

    }
private:
    int dir_x[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    int dir_y[8] = {1, 0, -1, 0, 1, -1, 1, -1};

    void dfs(vector<vector<char>>& board, int x, int y) {
        int cnt = 0;

        /*
        **  先判断[x, y]这个点周围8格有没有炸弹， 有的话用cnt计数
        */
        for(int i = 0; i < 8; ++i) {
            int tx = x + dir_x[i];
            int ty = y + dir_y[i];
            if(tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size())
                continue;
            
            cnt += (board[tx][ty] == 'M');
        }

        /*
        **  一次点击过程会从一个位置出发，逐渐向外圈扩散，所以这引导我们利用「搜索」的方式来实现。
        **  这里以深度优先搜索为例。在cnt为零的时候，对当前点相邻的未挖出的方块调用递归函数，
        **  否则将其改为数字，结束递归。
        */
        if(cnt > 0) {
            /* 规则 3，将其修改为数字 */
            board[x][y] = cnt + '0';
        } else {
            /* 
            **  如果 cnt 为零，即执行规则 2，此时需要将其改为'B' 
            **  且递归地处理周围的八个未挖出的方块，递归终止条件即为规则 4
            */
            board[x][y] = 'B';
            for(int i = 0; i < 8; ++i) {
                int tx = x + dir_x[i];
                int ty = y + dir_y[i];
                if(tx < 0 || tx >= board.size() ||
                   ty < 0 || ty >= board[0].size() || 
                   board[tx][ty] != 'E')
                    continue;

                dfs(board, tx, ty);
            }
        }
    }
};

int main() {
    vector<vector<char>> board = {{'E','E','E','E','E'},
                                  {'E','E','M','E','E'},
                                  {'E','E','E','E','E'},
                                  {'E','E','E','E','E'}};
    vector<int> click = {0, 2};

    Solution solution;
    board = solution.updateBoard(board, click);

    for(auto i : board) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }


    return 0;
}