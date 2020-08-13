#include <iostream>
#include <forward_list>

using namespace std;

int main() {
    forward_list<int> flst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    auto prev = flst.before_begin();
    auto curr = flst.begin();

    cout << "Original forward_list is ";
    for(auto &i : flst) {
        cout << i << " ";
    }
    cout << endl;

    while(curr != flst.end()) {
        if(*curr & 0x1) {
            // 奇数 => 复制奇数值
            curr = flst.insert_after(curr, *curr);      // insert_after() 在迭代器p之后的位置插入元素，返回一个指向最后一个插入元素的迭代器
            prev = curr;
            ++curr;
        } else {
            // 偶数 => 删除偶数值
            curr = flst.erase_after(prev);              // erase_after() 在迭代器p之后的位置删除元素，返回一个指向被删元素之后元素的迭代器
        }
    }

    cout << "Final forward_list is ";
    for(auto &i : flst) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}