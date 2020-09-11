#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool Fun_t(std::vector<float>& reg_objes) {
    bool ret = false;
    for (size_t i = 0; i < reg_objes.size(); i++) {
        if (reg_objes[i] < -0.3 || reg_objes[i] > 1.25) {
            reg_objes.erase(reg_objes.begin() + i);
            --i;
        }else{
            ret = true;
        }
    }
    return ret;

    // auto Iter1 = reg_objes.begin();
    // while (Iter1 != reg_objes.end()) {
    //     if (*Iter1 < -0.3 || *Iter1 > 1.25) {
    //         Iter1 = reg_objes.erase(Iter1);
    //     }else{
    //         ret = true;
    //         Iter1++;
    //     }
    // }

    // return ret;
}


int main() {
    std::vector<float> vfl = {-0.6, -0.5, 1, 1.2, 3};
    if(Fun_t(vfl)) {
        for(auto &i : vfl) {
            cout << i << " ";
        }
        cout << endl;
    }

    char *string_a = (char *)malloc(100 * sizeof(char));
    char string_b[100];

    cout << "sizeof(string_a): " << sizeof(string_a) << ", "
         << "sizeof(string_b): " << sizeof(string_b) << endl;

    vector<string> svec{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    cout << "origin: ";
    for(auto &i : svec) {
        cout << i << " ";
    }
    cout << ", size is " << svec.size() << endl;

    sort(svec.begin(), svec.end());
    cout << "sort: \t";
    for(auto &i : svec) {
        cout << i << " ";
    }
    cout << ", size is " << svec.size() << endl;

    /**
     *  unique返回的迭代器指向最后一个不重复元素之后的位置。
     *  此位置之后的元素仍存在，但是我们不知道它们的值是什么 
     */
    auto end_unique = unique(svec.begin(), svec.end()); 
    cout << "unique: ";
    for(auto &i : svec) {
        cout << i << " ";
    }
    cout << ", size is " << svec.size() << endl;
    /**
     *  unique: fox jumps over quick red slow the turtle the 
     *                                                   | 此位置之后的值无法确定了，相当于???
     *                                                end_unique
     */

    svec.erase(end_unique, svec.end());
    cout << "erase: \t";
    for(auto &i : svec) {
        cout << i << " ";
    }
    cout << ", size is " << svec.size() << endl;

    cout << boolalpha << (bool)1 << endl;


    return 0;
}