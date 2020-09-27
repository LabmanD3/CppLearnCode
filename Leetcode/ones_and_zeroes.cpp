/**
 *  474. 一和零
 * 
 *  在计算机界中，我们总是追求用有限的资源获取最大的收益。
 *  现在，假设你分别支配着 m个0 和 n个1。另外，还有一个仅包含 0和1字符串的数组。
 *  你的任务是使用给定的 m个0 和 n个1，找到能拼出存在于数组中的字符串的最大数量。
 *  每个 0和1至多被使用一次。
 * 
 *  示例 1:
 *      输入: strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
 *      输出: 4
 *      解释: 总共 4 个字符串可以通过 5 个 0 和 3 个 1 拼出，即 "10","0001","1","0" 。
 * 
 *  示例 2:
 *      输入: strs = ["10", "0", "1"], m = 1, n = 1
 *      输出: 2
 *      解释: 你可以拼出 "10"，但之后就没有剩余数字了。更好的选择是拼出 "0" 和 "1" 。
 * 
 *  提示：
 *      1 <= strs.length <= 600
 *      1 <= strs[i].length <= 100
 *      strs[i] 仅由 '0' 和 '1' 组成
 *      1 <= m, n <= 100
 *  
 *  来源：力扣（LeetCode）
 *  链接：https://leetcode-cn.com/problems/ones-and-zeroes
 *  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

class Solution {
public:

    int* numberOnesZeros(string str) {
        int *pi = new int[2]();
        if(str.empty()) {
            return pi;
        }

        // 计算str中0和1的数量，count[0]存0的数量，count[1]存1的数量
        for(int i = 0; i < str.size(); ++i) {
            pi[str[i] - '0']++;
        }
        
        return pi;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(int) * (m + 1) * (n + 1));
        
        for(auto str : strs) {
            int* count = numberOnesZeros(str);
            cout << "str is " << str 
                << ", zero is " << count[0]
                << ", one is " << count[1] << endl;
            for(int zero = m; zero >= count[0]; --zero) {
                for(int one = n; one >= count[1]; --one) {
                    dp[zero][one] = max(1 + dp[zero - count[0]][one - count[1]], dp[zero][one]);
                }
            }
        }
        cout << "-----------------" << endl;
        for(auto &i: dp) {
            for(auto &j : i) {
                cout << j << "  ";
            }
            cout << endl;    
        }
        cout << "-----------------" << endl;

        return dp[m][n];
    }
};

int main() {
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    for(auto str: strs) {
        cout << str << " ";
    }
    cout << endl;

    int m = 5, n = 3;

    Solution sol1;
    int res = sol1.findMaxForm(strs, m, n);
    cout << "result is " << res << endl;

    return 0;
}