/**
 *  详解参考：
 *  https://blog.csdn.net/u010320108/article/details/60878085 
 *  
 *  此方法用于计算一个二进制数中1的数量，时间复杂度为O(1)
 */

#include <iostream>

int swar_int32_t(int i) {
    i = (i & 0x55555555) + ((i >> 1) & 0x55555555);
    std::cout << "1. i = " << i << std::endl;
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    std::cout << "2. i = " << i << std::endl;
    i = (i & 0x0F0F0F0F) + ((i >> 4) & 0x0F0F0F0F);
    std::cout << "3. i = " << i << std::endl;
    i = (i * (0x01010101) >> 24);
    std::cout << "4. i = " << i << std::endl;

    return i;
}

int main() {
    std::cout << "请输入需要计算汉明重量的数：";
    int num;
    std::cin >> num;

    int ret = swar_int32_t(num);
    std::cout << "Num: " << num << ", 汉明重量为 " << ret << std::endl;

    return 0;
}