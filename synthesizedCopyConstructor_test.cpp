#include <iostream>
#include <string.h>

using namespace std;

class A
{
private:
    /* data */
    
public:
    char *str;

    A(const char *s = "ABC");
    virtual ~A();
};

A::A(const char *s)
{
    this->str = new char[strlen(s) + 1];
    memcpy(this->str, s, strlen(s) + 1);
}

A::~A()
{
    cout << "- destructor -" << endl;
    delete [] str;
}

int main()
{
    cout << "sizeof(A) = " << sizeof(A) << endl;            // sizeof(A) = 16, 因为虚函数表指针也占内存
    cout << "sizeof(int*) = " << sizeof(int*) << endl;      // sizeof(int*) = 8
    cout << "- 1 -" << endl;

    A *a1 = new A;
    cout << "- 2 -" << endl;

    /*
    **  1. 合成的拷贝构造函数
    */
    A *a2 = a1;                 // 使用合成的拷贝构造函数
    cout << "- 3 -" << endl;
    cout << "?ID.a1 = " << &a1 << endl;         // ?ID.a1 = 0x7ffdf2462a08
    cout << "?ID.a2 = " << &a2 << endl;         // ?ID.a2 = 0x7ffdf2462a10
    cout << "- 4 -" << endl;

    // 后果：
    cout << "&a1->str = " << &a1->str << ", a1->str = " << a1->str << endl;       // &a1->str = 0x5606ee0be280, a1->str = ABC
    cout << "&a2->str = " << &a2->str << ", a2->str = " << a2->str << endl;       // &a2->str = 0x5606ee0be280, a2->str = ABC
    /* 不难看出，使用合成的拷贝构造函数后，两个指针指向了同一块内存空间，&a1->str == &a2->str */

    // delete a1;                  // 此时只将a1 delete， a2 不delete
    cout << "&a2->str = " << &a2->str << ", a2->str = " << a2->str << endl;       // &a2->str = 0x5606ee0be280, a2->str =  
    /* &a2->str依然可以指向原先的空间 */
    cout << "- 5 -" << endl;

    memcpy(a2->str, "AAA", 3);
    cout << "&a2->str = " << &a2->str << ", a2->str = " << a2->str << endl;

    /* 此时再将a2 delete 就会报错 */
    // delete a2;                  // Segmentation fault (core dumped)
    cout << "- 6 -" << endl;

    /*
    **  2. 合成的拷贝赋值运算符
    */
    A *a3 = new A("abc");
    cout << "&a3->str = " << &a3->str << ", a3->str = " << a3->str << endl;
    char *temp = a3->str;
    cout << "temp address is " << &temp << ", value is " << temp << endl;

    a3 = a2;                    // 使用合成的拷贝赋值运算符也是一样的
    cout << "&a2->str = " << &a2->str << ", a2->str = " << a2->str << endl;
    cout << "&a3->str = " << &a3->str << ", a3->str = " << a3->str << endl;
    /* 地址相同 &a2->str == &a3->str */

    memcpy(temp, "bbb", 3);         // 原有的a3->str内存并没有被释放，会造成内存泄露
    cout << "temp address is " << &temp << ", value is " << temp << endl;

    delete a2;
    cout << "&a3->str = " << &a3->str << ", a3->str = " << a3->str << endl;
    /* 同样不能多次释放同一块内存空间 */

    // delete a3;                  // Segmentation fault (core dumped)

    return 0;
}