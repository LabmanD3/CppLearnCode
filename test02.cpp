#include <iostream>
#include <vector>

using namespace std;

class A
{
protected:
    int Aflag;
public:
    A(/* args */): Aflag(22) {};
    ~A() {};
};

class B : A
{
private:
    int Bflag;
public:
    B(/* args */): Bflag(11) {};
    ~B() {};

    void Print();
};

void B::Print() {
    // 区别： protected: -> true 和 private: -> false -> error: ‘int A::Aflag’ is private within this context
    cout << "Bflag is " << Bflag << ", Aflag is " << Aflag << endl;
}

int main() {
    A a;
    B b;

    b.Print();
    // cout << "Aflag is " << a.Aflag << endl;         // error: ‘int A::Aflag’ is protected within this context

    /* ------------------------------------- */

    vector<vector<char>> boardA(3, {'a', 'b', 'c'});
    vector<vector<char>> boardB{{'a', 'b', 'c', '1'},
                                {'d', 'e', 'f', '2'},
                                {'g', 'h', 'i', '3'}};

    for(auto i : boardA) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;

    for(auto i : boardB) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "boardA[1][2] is " << boardA[1][2] << endl;
    cout << "boardB[2][2] is " << boardB[2][2] << endl;

    int width;
    int length;

    width = boardB.size();
    cout << "width: " << width << endl;

    length = boardB[0].size();
    cout << "length: " << length << endl;


    return 0;
}