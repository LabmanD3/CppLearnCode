#include <string.h>
#include "Constructor.h"

String::String(int size)                    // constructor with parameter
{
    cout << "*** constructor(int size) ***" << endl;
    if(size < 0)
        size = 0;
    this->ptr = new char[size]();
}

String::String(const char *p)               // constructor
{
    cout << "*** constructor ***" << endl;
    this->ptr = new char[strlen(p)+1];
    // cout << "strlen size:" << strlen(p) << endl;
    memcpy(this->ptr, p, strlen(p)+1);

}

String::String(const String &s)             // copy constructor
{
    cout << "*** copy constructor ***" << endl;
    this->ptr = new char[strlen(s.ptr)+1];
    memcpy(this->ptr, s.ptr, strlen(s.ptr)+1);
}

String::~String()                           // destructor
{
    cout << "*** destructor ***" << endl;
    delete [] ptr;
}

ostream& operator<<(ostream &cout, String &s)           // overloaded operator
{
    cout << "*** '<<' overloaded operator ***" << endl;
    cout << s.ptr;
}

String& String::operator=(const String &s)              // copy-assginment operator
{
    cout << "*** copy-assginment operator ***" << endl;
    // 1. 防止自赋值
    if(this == &s)
        return *this;
    cout << "- 1 -" << endl;
    // 2. 释放原有空间
    delete [] this->ptr;
    cout << "- 2 -" << endl;
    // 3. 分配新空间
    this->ptr = new char[strlen(s.ptr)+1];
    cout << "- 3 -" << endl;
    // 4. 把目标空间中的值拷贝到新空间
    strcpy(this->ptr, s.ptr);
    cout << "- 4 -" << endl;
    // 5. 返回自引用
    return *this;
}

int main() {

    cout << "<<<< str1 >>>>" << endl;
    String str1 = "asd";    // 直接初始化
    cout << str1 << endl;

    cout << "<<<< str2 >>>>" << endl;
    String str2 = str1;     // 拷贝初始化
    cout << str2 << endl;

    cout << "<<<< str3 >>>>" << endl;
    String str3;
    str3 = str1;            // 拷贝赋值运算符
    cout << str3 << endl; 

    cout << "<<<< str4 >>>>" << endl;
    String *p = new String;
    String str4(*p);        // 拷贝构造函数将*p拷贝到str4中
    cout << str4 << endl;

    // String str3 = 10;   // no suitable constructor exists to convert from "int" to "String"

    return 0;
}