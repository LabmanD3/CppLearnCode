/*
**  Best Time to Buy and Sell Stock with Cooldown
**
**  最佳买卖股票时机含冷冻期
**
**  给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​
**
**  设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
**
**      1. 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
**      2. 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
**
**  来源：力扣（LeetCode）
**  链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
**  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**
*/
#ifndef LEETCODE_309_H
#define LEETCODE_309_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        **    继续持有          仍不买入
        **    ↙-----、   买入   ↙-----、
        **     持有--  <------  不持有-
        **      |             --
        **      | 卖         --
        **      | 出       --   冷冻期结束转为不持有，然后才能买入
        **      ↓       --
        **    冷冻期 ----
        */

        /* 解法一 ：用了两个数组 */
        // int len = prices.size();
        // if(len < 2) 
        //     return 0;
        // int *hold = new int[len]();
        // int *nothold = new int[len]();
        // hold[0] = -prices[0];

        // for(int i = 1; i < len; ++i) {
        //     if(i >= 2)
        //         hold[i] = max(hold[i-1], nothold[i-2] - prices[i]);
        //     else
        //         hold[i] = max(hold[i-1], -prices[i]);
            
        //     nothold[i] = max(nothold[i-1], hold[i-1] + prices[i]);
        // }
        // return nothold[len-1];

        /* 解法二 ：三个变量(三种状态： 持有/冷冻期/不持有) */
        int len = prices.size();
        if(len < 2)
            return 0;
        int dp1 = -prices[0];       // dp1 = 持有股票
        int dp2 = 0;                // dp2 = 冷冻期，不可买
        int dp3 = 0;                // dp3 = 不持有股票，可买
        for(int i = 1; i < len; ++i) {
            int temp1 = max(dp1, dp3 - prices[i]);  // 要么保持上一天的持有股票状态（买入未卖出），要么从不持有状态买入
            int temp2 = dp1 + prices[i];            // 将持有的卖出才进入冷冻期
            int temp3 = max(dp2, dp3);              // 进入可买状态，可能是从冷冻期转来，也可能仍在可买状态
            dp1 = temp1;
            dp2 = temp2;
            dp3 = temp3;
        }
        return max(dp2, dp3);
    }
};

#endif // LEETCODE_309_H