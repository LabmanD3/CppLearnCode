#include <iostream>
#include <vector>

using namespace std;

constexpr int scale(int cnt) {
    return 2*cnt;
}

enum unitStatus
{
    REDFLAG,
    DIGGED,
    UNDIGGED
};

struct unit
{
    unitStatus curStatus;
    bool isBomb;
    int bombNum;
    unit(): curStatus(UNDIGGED), isBomb(false), bombNum(0) {};
    ~unit() = default;
};

template <class... T>
void f(T... args)
{    
    cout << sizeof...(args) << endl; //打印变参的个数
    // parameter packs expanded with ‘...’
}


int main() {
    const int i = 3;
    int j = 4;
    int a[scale(j)] = {0, 1, 2};

    constexpr int foo = scale(i);

    cout << "a.size() is " << sizeof(a)/sizeof(typeof(*a)) << endl;

    vector<unit> vunit;
    
    f();
    f(1, 1.3);
    f(1, 3.1, "");

    return 0;
}