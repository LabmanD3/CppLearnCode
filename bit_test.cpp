#include <iostream>

using namespace std;

typedef struct 
{
    unsigned int a:8;
    unsigned int b:8;
    int c:16;
} Bit;


int main()
{
    Bit B;
    B.a = 125;
    B.b = 121;
    B.c = 65535;
    cout << "sizeof(Bit) = " << sizeof(B) << endl;      // 4
    cout << "a = " << B.a << endl;
    cout << "b = " << B.b << endl;
    cout << "c = " << B.c << endl;

    return 0;
}