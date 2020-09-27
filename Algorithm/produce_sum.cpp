/**
 *  链接：https://www.nowcoder.com/questionTerminal/2e4363c23c6741f98319d5a7e3882325
 *  来源：牛客网
 * 
 *  在vivo产线上，每位职工随着对手机加工流程认识的熟悉和经验的增加，日产量也会不断攀升。
 *  假设第一天量产1台，接下来2天(即第二、三天)每天量产2件，接下来3天(即第四、五、六天)每天量产3件 ... ... 
 *  以此类推，请编程计算出第n天总共可以量产的手机数量。
 * 
 *  Such as:
 *  input: 11
 *  output: 35
 *  第11天工人总共可以量产的手机数量
 */

#include <iostream>

class Solution {
public:
    /**
     *
     * @param n int整型 第n天
     * @return int整型
     */
    int solution(int n) {
        // write code here
        int ans = 0;
        for(int i=1; n>0; ++i){
            ans += i * std::min(i, n);
            n -= i;
        }
        return ans;
    }
};

int main() {

    return 0;
}