#include <list>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<string> svec1(10);
    vector<string> svec2(24);

    cout << "svec1[0] address is " << &svec1[0] << ", svec1 size is " << svec1.size() << endl;
    /* svec1[0] address is 0x55a09c582e70, svec1 size is 10 */
    cout << "svec2[0] address is " << &svec2[0] << ", svec2 size is " << svec2.size() << endl;
    /* svec2[0] address is 0x55a09c582fc0, svec2 size is 24 */

    cout << "svec1 capacity: " << svec1.capacity() << endl;
    cout << "svec2 capacity: " << svec2.capacity() << endl;

    /*
    **  svec2.assign(1024, "Hello!")之后，svec2[0]地址改变。
    **  assgin中的size若大于原容器，则会重新分配一块内存空间，小于则不改变。
    **  因为vector和string添加元素可能引起整个对象存储空间的重新分配。
    */

    svec2.assign(1024, "Hello!");
    cout << "- assign -" << endl;
    cout << "svec1[0] address is " << &svec1[0] << ", svec1 size is " << svec1.size() << endl;
    /* svec1[0] address is 0x55a09c582e70, svec1 size is 10 */
    cout << "svec2[0] address is " << &svec2[0] << ", svec2 size is " << svec2.size() << endl;
    /* svec2[0] address is 0x55a09c5836e0, svec2 size is 1024 */

    cout << "svec1 capacity: " << svec1.capacity() << endl;
    cout << "svec2 capacity: " << svec2.capacity() << endl;

    /*
    **  swap(svec1, svec2)之后， svec1[0]与svec2[0]地址交换了。
    **  说明swap交换了两个容器的内部数据结构
    */
    
    swap(svec1, svec2);
    cout << "- swap -" << endl;
    cout << "svec1[0] address is " << &svec1[0] << ", svec1 size is " << svec1.size() << endl;
    /* svec1[0] address is 0x55a09c5836e0, svec1 size is 1024 */
    cout << "svec2[0] address is " << &svec2[0] << ", svec2 size is " << svec2.size() << endl;
    /* svec2[0] address is 0x55a09c582e70, svec2 size is 10 */

    svec1.assign(48, "Hey!");
    cout << "- assign -" << endl;
    cout << "svec1[0] address is " << &svec1[0] << ", svec1 size is " << svec1.size() << endl;
    /* svec1[0] address is 0x55a09c5836e0, svec1 size is 48 */
    cout << "svec2[0] address is " << &svec2[0] << ", svec2 size is " << svec2.size() << endl;
    /* svec2[0] address is 0x55a09c582e70, svec2 size is 10 */

    return 0;
}