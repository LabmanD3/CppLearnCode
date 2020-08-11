#include <iostream>

using namespace std;

class A {
public:
	A() : x1(3), x2(x1){}
 
	// A(const A& c) : x1(c.x1), x2(x1){}   // 初始化表： x2(x1)重新初始化，引用新的x1
	int x1;
	int &x2;
};
 
int main() {
	A a;
	A b = a;
	cout << "b中x2=" << b.x2 << endl;
	b.x1 = 5;
	cout << "b中x1=" << b.x1 << "  b中x2=" << b.x2 << ", a中x1=" << a.x1 << "  a中x2=" << a.x2 << endl;
    /* 
    ** 1. 使用默认的拷贝构造函数时
    ** > b中x1=5  b中x2=3, a中x1=3  a中x2=3
    ** b中的x1与x2未形成绑定
    ** 
    ** 2. 使用自定义的拷贝构造函数时，即去掉上方拷贝构造函数的注释
    ** > b中x1=5  b中x2=5, a中x1=3  a中x2=3
    ** b中的x1能与x2建立连接
    */

	a.x1 = 5;
	cout << "a中x1=" << a.x1 << "  a中x2=" << a.x2 << ", b中x1=" << b.x1 << "  b中x2=" << b.x2 << endl;
    /* 
    ** 1. 使用默认的拷贝构造函数时
    ** > a中x1=5  a中x2=5, b中x1=5  b中x2=5 
    ** 反而是b中的x2与a中的x1有关
    */

    return 0;
}
 
 
