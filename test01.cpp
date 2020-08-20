#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;

void Print(vector<int> &a) {
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    vector<int> tmp(10);
    for (int i = 0; i < tmp.size(); ++i) {
        cout << tmp[i] << " ";
    }
    cout << endl;
}

/*
**  整型数组 arr[]中有n个无序的int，这些整数的取值范围都在0-20之间  
**  要求在 O(n)的时间复杂度中把这 n个数按照从小到大的顺序打印出来。
*/
void func (vector<int> &arr) {
	vector<int> temp(21);						// 数值范围0~20
	for (int i = 0; i < arr.size(); i++) {
		temp[arr[i]]++;							// 以数值为下标，出现过就+1
	}
    // for (int i = 0; i < temp.size(); ++i) {
    //     cout << temp[i] << " ";
    // }
    // cout << endl;

	/* 顺序打印 */
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < temp[i]; j++) {
			/* temp[i] 就是 i出现的次数 */
            cout << i << " ";
		}
	}
	cout << endl;
}

int main() {
    vector<int> a{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1 , 3, 4, 5, 1, 2};

    Print(a);
    func(a);

    const char *cp = "Hello World!!!";
    char noNull[] = {'H', 'i', 'm', 'a', 'n'};

    string s1(cp);
    cout << "s1: " << s1 << endl;
    string s2(noNull, 2);
    cout << "s2: " << s2 << endl;
    // string s3(noNull);           // false, 因为noNull没有空字符
    // cout << "s3: " << s3 << endl;
    string s4(s1, 2);
    cout << "s4: " << s4 << endl;

    cout << "------------------------" << endl;

    array<int, 10> a1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    array<int, 5> a2 = {0};
    cout << "a1: ";
    for(auto i : a1) {
        cout << i << " ";
    }
    cout << endl;

    cout << "a2: ";
    for(auto i : a2) {
        cout << i << " ";
    }
    cout << endl;

    // a1 = a2;    // false, 因为两者元素类型必须相同，array包括容器大小
    // swap(a1, a2);    // false, 因为两者元素类型必须相同，array包括容器大小
    
    return 0;
}
