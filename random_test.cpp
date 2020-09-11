#include <iostream>
#include <random>
#include <vector>

using namespace std;

vector<unsigned> bad_randVec() {
    default_random_engine e;
    uniform_int_distribution<unsigned> u(0, 10);
    vector<unsigned> ret;
    for(int i = 0; i < 100; ++i) {
        ret.emplace_back(u(e));
    }
    return ret;
}

int main() {
    int min = 0;
    int max = 7;
    int sum = 10;
    vector<vector<char>> map;

    for(int i = 0; i < max + 1; ++i) {
        vector<char> perRow;
        for(int j = 0; j < max + 1; ++j) {
            char temp = 'O';
            perRow.emplace_back(temp);
        }
        map.emplace_back(perRow);
    }

	default_random_engine e(static_cast<unsigned>(time(nullptr)));
    uniform_int_distribution<unsigned> uRow(min, max);
    uniform_int_distribution<unsigned> uCol(min, max);

    for(int num = 0; num < sum;){
        int i = uRow(e);
        int j = uCol(e);
        if(map[i][j] == 'O') {
            map[i][j] = 'X';
            ++num;
        }
    }

    for(auto &i : map) {
        for(auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;

    /********************************************/
    default_random_engine E;        // 因为每次都会使用默认种子，产生相同的序列
    uniform_int_distribution<unsigned> U(0, 10);
    for(int i = 0; i < 15; ++i) {
        cout << U(E) << " ";        // 每次运行./a.out 都会打印相同的数列
    }
    cout << endl;
    /********************************************/

    vector<unsigned> vec1(bad_randVec());
    vector<unsigned> vec2(bad_randVec());
    cout << ((vec1 == vec2) ? "equal" : "not equal") << endl;
    // 打印了 equal 说明: vec1 == vec2， 理由同上

    default_random_engine e2;
    normal_distribution<> n(4, 1.5);
    vector<unsigned> vals(9);           // 9个元素均为0
    for(int i = 0; i != 200; ++i) {
        unsigned v = lround(n(e));
        if(v < vals.size()) 
            ++vals[v];
        else 
            cout << "v > vals.size()" << endl;
    }
    for(int j = 0; j != vals.size(); ++j) {
        cout << j << ": " << string(vals[j], '*') << endl;
    }

    cout << "Bernoulli:" << endl;
    bernoulli_distribution b(0.6);
    vector<unsigned> vv(2); 
    for(int i = 0; i != 200; ++i) {
        if(b(e)){
            ++vv[1];
        } else {
            ++vv[0];
        }
    }
    for(int j = 0; j != vv.size(); ++j) {
        cout << j << ": " << string(vv[j], '*') << endl;
    }

    return 0;
}