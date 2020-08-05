#include <iostream>

using namespace std;

class A
{
	public:
		virtual void func() { cout << "A::fun" << endl;}
};

class B : public A
{
	public:
		virtual void func() { cout << "B::fun" << endl;}
		//virtual void func(int a = 1) { cout << "B::fun" << endl;}
};

int main()
{
	A *p1 = new A;
	A *p2 = new B;
	p1->func();	//A::fun
	p2->func();	//B::fun

	B b;		//父类虚函数表中的func()的位置被替换成了子类的func()函数指针
	A *p3 = &b;	//这样，我们就可以任一静态类型的父类来指向子类，并调用子类的func()
	p3->func();	//B::fun

	return 0;
}
