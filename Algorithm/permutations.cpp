/*
**  47. 全排列(Permutations)
**
**  给定一个 包含重复数字的序列，返回其所有可能的全排列。
**
**  示例:
**
**  输入: [2,2,1,1]
**  输出:
**  [
**      [1,1,2,2],
**      [1,2,1,2],
**      [1,2,2,1],
**      [2,1,1,2],
**      [2,1,2,1],
**      [2,2,1,1]
**  ]
**
**  来源：力扣（LeetCode）
**  链接：https://leetcode-cn.com/problems/permutations-ii
**  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int len;
    vector<vector<int>> ret;

    void printVector() const {
        for (auto &i : ret) {
            for (auto &j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
  
    void permuteHelper(vector<int>& nums, int i) {
        if (i == len - 1) {
            ret.emplace_back(nums);
        }
        else {
            for (int j = i; j < len; ++j) {
                // 剪枝
                if (j > i && nums[j] == nums[j - 1]) 
                    continue;
                // 当两个数相同就不用执行{}里的交换操作了
                if (j == i || nums[j] != nums[i]) {
                    // 交换两个数
                    swap(nums[i], nums[j]);
                    // 继续递归填下一个数
                    permuteHelper(nums, i+1);
                    // 撤销操作，（回溯）
                    swap(nums[i], nums[j]);
                } 
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        len = nums.size();   
        if (len < 2) {
            ret.emplace_back(nums);
            return ret;
        }

        permuteHelper(nums, 0);
        
        return ret;
    }
};

int main() {
    vector<int> nums = {2, 2, 1, 1};

    Solution test;

    sort(nums.begin(), nums.end());
    test.permuteUnique(nums);

    cout << "Result: " << endl;
    test.printVector();

    return 0;
}