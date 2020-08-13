#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> lst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    auto iter = lst.begin();

    cout << "Original list is ";
    for(auto &i : lst) {
        cout << i << " ";
    }
    cout << endl;

    while(iter != lst.end()) {
        if(*iter & 0x1) {
            // 奇数 => 复制奇数值
            iter = lst.insert(iter, *iter);         // insert() 在迭代器p之前的位置创建一个元素，返回指向新添加的元素的迭代器
            advance(iter, 2);
        } else {
            // 偶数 => 删除偶数值
            iter = lst.erase(iter);                 // erase() 删除迭代器p所指的元素，返回一个指向被删元素之后的迭代器            
        }
    }

    cout << "Final list is ";
    for(auto &i : lst) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}