#include <iostream>
#include <vector>
#include <deque>
#include <list>

using namespace std;

int main()
{
    int ia[] = {100, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};

    deque<int> de(ia, end(ia));
    deque<int>::iterator Iter1 = de.begin();

    cout << "deque : ";
    for(auto &i : de)
        cout << i << " ";
    cout << endl;

    cout << "deque front is " << *Iter1 << " before pop_front()" << endl;
    // de.pop_front();
    /* 
    **  保证每次改变容器的操作之后都能正确地重新定位迭代器 
    **  de.pop_front(); 可以改为
    **  Iter1 = de.erase(Iter1);
    */
    Iter1 = de.erase(Iter1);
    cout << "deque front is " << *Iter1 << " after pop_front()" << endl;

    deque<int>::iterator Iter2 = de.begin();
    cout << "deque real front is " << *Iter2 << endl;

    cout << "deque : ";
    for(auto &i : de)
        cout << i << " ";
    cout << endl;

    return 0;
}