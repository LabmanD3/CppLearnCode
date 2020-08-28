#include <iostream>
#include <vector>

#include "AVLTree.h"
#include "BSTree.h"

using namespace std;

int main() {
    vector<int> a = {5, 3, 9, 1, 8, 6, 4, 11, 7, 2};
    BSTree<int> bst;

    cout << "a[] is \t\t";
    for(auto i : a) {
        cout << i << " ";
        bst.addNode(i);
    }
    cout << endl;

    cout << "BSTree is \t";
    bst.printInOrder();
    cout << endl;
    cout << "Depth is " << bst.depth() << endl;

    cout << "Node sum is " << bst.size() << endl;

    /*// 查找结点
    int findNum;
    cin >> findNum;
    if(bst.searchData(findNum))
        cout << "- Found! -" << endl;
    else
        cout << "- Not Found! -" << endl;

    cout << "Max: " << bst.maximum() << endl;
    cout << "Min: " << bst.minimum() << endl;
    */

    /*// 删除结点
    int delNum;
    cin >> delNum;
    if(bst.deleteNode(delNum))
        cout << "- Delete successful -" << endl;
    else
        cout << "- Delete failed -" << endl;

    cout << "BSTree is \t";
    bst.printInOrder();
    cout << endl;
    */

    // 拷贝构造函数测试
    cout << "---- bst2 Create ----" << endl;
    BSTree<int> bst2 = bst;
    cout << "BSTree2 is \t";
    bst2.printInOrder();
    cout << endl;

    cout << "Node sum is " << bst2.size() << endl;

    // 赋值构造运算符测试
    cout << "---- bst3 Create ----" << endl;
    BSTree<int> bst3;
    for(int i = 0; i < (a.size()/2); ++i) {
        bst3.addNode(a[i]);
    }
    cout << "BSTree3 is \t";
    bst3.printInOrder();
    cout << endl;

    cout << "Node sum is " << bst3.size() << endl;

    bst3 = bst;
    cout << "BSTree3 is \t";
    bst3.printInOrder();
    cout << endl;

    cout << "Node sum is " << bst3.size() << endl;

    cout << "~~~~ AVLTree Debug Beginning ~~~~" << endl;
    AVLTree<int> *avlTree1 = new AVLTree<int>;
    for(int i = 0; i < a.size(); ++i) {
        avlTree1->addNode(a[i]);
    }
    if(avlTree1->isBalanced()) {
        cout << "avltree1 is balanced !" << endl;
        avlTree1->printInOrder();
        cout << endl;
    } else {
        cout << "avltree1 isn't balanced !" << endl;
    }

    int delNum;
    cout << "Delete one node: ";
    cin >> delNum;

    avlTree1->deleteNode(delNum);
    avlTree1->printInOrder();
    cout << endl;


    return 0;
}