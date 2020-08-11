/*
**  46. 全排列(Permutations)
**
**  给定一个 无重复 数字的序列，返回其所有可能的全排列。
**
**  示例:
**
**  输入: [1,2,3]
**  输出:
**  [
**    [1,2,3],
**    [1,3,2],
**    [2,1,3],
**    [2,3,1],
**    [3,1,2],
**    [3,2,1]
**  ]
**
**  来源：力扣（LeetCode）
**  链接：https://leetcode-cn.com/problems/permutations
**  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**
*/

#ifndef PERMUTATIONS_46_H
#define PERMUTATIONS_46_H

#include <vector>

using namespace std;

class Solution {
public:
    int len;
    vector<vector<int>> ret;
  
    void permuteHelper(vector<int>& nums, int i) {
        if (i == len - 1)
            ret.emplace_back(nums);
        else {
            for (int j = i; j < len; ++j) {
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
    
    vector<vector<int>> permute(vector<int>& nums) {
        len = nums.size();   
        if (len < 2) {
            ret.emplace_back(nums);
            return ret;
        }

        permuteHelper(nums, 0);
        
        return ret;
    }
};

#endif // PERMUTATIONS_46_H