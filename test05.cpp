#include <iostream>
#include <map>
#include <set>
#include <string.h>

int main() {
    // set
    std::set<int> iset = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::set<int>::iterator set_it = iset.begin();
    while(set_it != iset.end()) {
        // *set_it = 42;     错误： set中的关键字是只读的， set的迭代器是 const的
        // > error: assignment of read-only location ‘set_it.std::_Rb_tree_const_iterator<int>::operator*()’
        std::cout << *set_it << " ";
        ++set_it;
    }
    std::cout << std::endl;

    // map
    std::map<int, int> imap = {
            {0, 1}, 
            {2, 3}, 
            {4, 5}
        };
    std::cout << imap[1] << std::endl;    // 使用下标运算符访问不存在的元素 == 添加该新元素(初始值为0)
    std::map<int, int>::iterator map_it = imap.begin();
    while(map_it != imap.end()) {
        // map_it->first = 99;      错误： 关键字是 const的
        // > error: assignment of read-only member ‘std::pair<const int, int>::first’
        std::cout << "{" << map_it->first << ", ";
        // ++map_it->second;
        std::cout << map_it->second << "} ";
        ++map_it;
    }
    std::cout << std::endl;

    // auto
    int a = 10;
    float b = 11.1;
    auto c = a + b;
    std::cout << "c: " << c << std::endl;

    int dp[2][2];
    memset(dp, 0, sizeof(int)*(2 * 2));
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            std::cout << dp[i][j] << " ";
        }
        std::cout << std::endl;
    }
    

    return 0;
}