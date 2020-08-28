#ifndef BSTREE_H
#define BSTREE_H

/*
**  ** 二叉查找树 **
**  
**  此处注意两点：
**      第1点：采用了STL模板。因此，二叉查找树支持任意数据类型。
**      第2点：将二叉查找树的"声明"和"实现"都位于BSTree.h中。这是因为，在二叉查找树的实现采用了模板；而C++编译器不支持对模板的分离式编译！
*/

#include <iostream>
using namespace std;

template <class T>
class BSTNode
{
public:
    T data;                    // 结点数值
    BSTNode *left;             // 左子树
    BSTNode *right;            // 右子树
    BSTNode *parent;           // 父结点

    BSTNode(T value, BSTNode *l, BSTNode *r, BSTNode *p):
        data(value), left(l), right(r), parent(nullptr) {}
};

template <class T>
class BSTree
{
protected:
    BSTNode<T> *mRoot;          // 根结点
    int nodeSum;                // 结点总数

public:
    BSTree(): mRoot(nullptr), nodeSum(0) {};        // 构造函数
    ~BSTree();                                      // 析构函数
    BSTree(const BSTree<T> &oriTree);                   // 拷贝构造函数
    BSTree<T> &operator=(const BSTree<T> &otherTree);     // 赋值拷贝运算符

    int size() const;                           // 返回结点总数
    int depth() const;                         // 查看树的深度大小
    T minimum();                         // 查找最小结点
    T maximum();                         // 查找最大结点
    BSTNode<T>* searchData(T dst);              // 查找结点
    void printPreOrder();                // 前序遍历打印
    void printInOrder();                 // 中序遍历打印
    void printPostOrder();               // 后序遍历打印
    volatile void addNode(T newData);                  // 添加结点
    volatile bool deleteNode(T dst);                   // 删除指定结点
    void destroyTree();                      // 销毁二叉树

protected:
    BSTNode<T>* copyTree(BSTNode<T>* root);                 // 拷贝树 -> 拷贝构造函数
    BSTNode<T>* searchData(BSTNode<T>* root, T dst) const;              // 查找结点
    BSTNode<T>* minimum(BSTNode<T>* root) const;                     // 查找最小结点
    BSTNode<T>* maximum(BSTNode<T>* root) const;                     // 查找最大结点
    int depth(BSTNode<T> *root) const;                          // 查看该结点的深度大小
    void printPreOrder(BSTNode<T>* root) const;                   // 前序遍历打印
    void printInOrder(BSTNode<T>* root) const;                    // 中序遍历打印
    void printPostOrder(BSTNode<T>* root) const;                  // 后序遍历打印
    volatile void addNode(BSTNode<T>* &root, BSTNode<T>* &node);              // 添加结点
    volatile bool deleteNode(BSTNode<T>* &node);                             // 删除指定数据
    void destroyTree(BSTNode<T>* &root);                           // 销毁二叉树
};


/*
**  析构函数
*/
template <class T>
BSTree<T>::~BSTree() {
    destroyTree();
}

/*
**  拷贝构造函数
*/
template <class T>
BSTree<T>::BSTree(const BSTree<T> &oriTree): nodeSum(0) {
    this->mRoot = copyTree(oriTree.mRoot);
}

template <class T>
BSTNode<T>* BSTree<T>::copyTree(BSTNode<T>* root) {
    if(root == nullptr)
        return nullptr;

    BSTNode<T> *newRoot = nullptr;
    if(!(newRoot = new BSTNode<T>(root->data, nullptr, nullptr, nullptr))){
        return nullptr;
    } else {
        nodeSum++;
    }
        
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);

    return newRoot;
}

/*
**  赋值拷贝函数
*/
template <class T>
BSTree<T> &BSTree<T>::operator=(const BSTree<T> &otherTree) {
    // 1. 防止自赋值
    if(this == &otherTree)
        return *this;

    // 2. 释放原有空间
    destroyTree(this->mRoot);

    // 3. 分配新空间
    // 4. 把目标空间中的值拷贝到新空间
    this->mRoot = copyTree(otherTree.mRoot);

    // 5. 返回自引用
    return *this;
}

/*
**  返回结点总数
*/
template <class T>
int BSTree<T>::size() const {
    return this->nodeSum;
}

/*
**  (递归实现)查找"二叉树"中键值为dst的节点
*/
template <class T>
BSTNode<T>* BSTree<T>::searchData(BSTNode<T>* root, T dst) const {
    if(root != nullptr) {
        if(root->data == dst) {
            cout << "查找值存在，值为" << root->data << endl;
            return root;
        } else if(dst < root->data) {
            searchData(root->left, dst);        // 递归查找左子树
        } else if(dst > root->data) {
            searchData(root->right, dst);       // 递归查找右子树
        }
    } else {
        cout << "未找到查找值" << endl;
        return nullptr;
    }   
}

template <class T>
BSTNode<T>* BSTree<T>::searchData(T dst) {
    return searchData(mRoot, dst);
}

/*
**  查找最小结点：返回root为根结点的二叉树的最小结点。
*/
template <class T>
BSTNode<T>* BSTree<T>::minimum(BSTNode<T>* root) const {
    if(root == nullptr) {
        return nullptr;
    }

    while(root->left != nullptr) {
        root = root->left;
    }

    return root;
}

template <class T>
T BSTree<T>::minimum() {
    BSTNode<T>* min = minimum(mRoot);
    
    if(min != nullptr)
        return min->data;

    return (T)NULL;
}

/*
**  查找最大结点：返回root为根结点的二叉树的最大结点。
*/
template <class T>
BSTNode<T>* BSTree<T>::maximum(BSTNode<T>* root) const {
    if(root == nullptr) {
        return nullptr;
    }

    while(root->right != nullptr) {
        root = root->right;
    }

    return root;
}

template <class T>
T BSTree<T>::maximum() {
    BSTNode<T>* max = maximum(mRoot);

    if(max != nullptr)
        return max->data;

    return (T)NULL;
}

/*
**  查看树的深度大小
*/
template <class T>
int BSTree<T>::depth(BSTNode<T> *root) const {
    if(root == nullptr)
        return 0;
    
    int ldep = depth(root->left);
    int rdep = depth(root->right);

    return (ldep > rdep? ldep: rdep) + 1;
}

template <class T>
int BSTree<T>::depth() const {
    return depth(this->mRoot);
}


/*
**  前序遍历"二叉树"
*/
template <class T>
void BSTree<T>::printPreOrder(BSTNode<T>* root) const {
    if(root != nullptr) {
        cout << root->data << " ";
        if(root->left != nullptr)
            printPreOrder(root->left);
        if(root->right != nullptr)
            printPreOrder(root->right);
    }
}

template <class T>
void BSTree<T>::printPreOrder() {
    printPreOrder(mRoot);
}

/*
**  中序遍历"二叉树"
*/
template <class T>
void BSTree<T>::printInOrder(BSTNode<T>* root) const {
    if(root != nullptr) {
        if(root->left != nullptr)
            printInOrder(root->left);
        cout << root->data << " ";
        if(root->right != nullptr)
            printInOrder(root->right);
    }
}

template <class T>
void BSTree<T>::printInOrder() {
    printInOrder(mRoot);
}

/*
**  后序遍历"二叉树"
*/
template <class T>
void BSTree<T>::printPostOrder(BSTNode<T>* root) const {
    if(root != nullptr) {
        if(root->left != nullptr)
            printPostOrder(root->left);
        if(root->right != nullptr)
            printPostOrder(root->right);
        cout << root->data << " ";
    }
}

template <class T>
void BSTree<T>::printPostOrder() {
    printPostOrder(mRoot);
}

/*
**  添加结点
*/
template <class T>
volatile void BSTree<T>::addNode(BSTNode<T>* &root, BSTNode<T>* &node) {
    if(root == nullptr) {
        this->nodeSum++;
        root = node;
    } else {
        if(root->data == node->data) {
            return ;
        } else if(node->data < root->data) {
            //  往左子树插入
            this->addNode(root->left, node);
            root->left->parent = root;
        } else if(node->data > root->data) {
            //  往右子树插入
            this->addNode(root->right, node);
            root->right->parent = root;
        }
    }
}

template <class T>
volatile void BSTree<T>::addNode(T newData) {
    BSTNode<T> *newNode = nullptr;

    if(!(newNode = new BSTNode<T>(newData, nullptr, nullptr, nullptr)))
        return ;

    this->addNode(mRoot, newNode);
}

/*
**  找到指定结点，并删除
*/
template <class T>
volatile bool BSTree<T>::deleteNode(BSTNode<T>* &node) {
    if(node == nullptr) {
        return false;
    }

    if(node->left == nullptr && node->right == nullptr) {
        /* 左右子树均不存在，即该删除结点度为0 */
        if(node->parent == nullptr) {
            // 删除结点是根结点
        } else if(node->parent->left == node) {
            // 删除结点是父结点的左孩子
            node->parent->left = nullptr;
        } else if (node->parent->right = node) {
            // 删除结点是父结点的右孩子
            node->parent->right = nullptr;
        }
        delete node;
        node = nullptr;
    } else if(node->left == nullptr || node->right == nullptr) {
        /* 删除结点度为1 */
        if(node->parent == nullptr) {
            // 删除结点是根结点
        } else if(node->parent->left == node) {
            /* 删除结点是父结点的左孩子 */
            if(node->left != nullptr) {
                /* 删除结点有左孩子 */
                node->parent->left = node->left;
                node->left = nullptr;
            } else {
                /* 删除结点有右孩子 */
                node->parent->left = node->right;
                node->right = nullptr;
            }
        } else if(node->parent->right == node) {
            /* 删除结点是父结点的右孩子 */
            if(node->left != nullptr) {
                /* 删除结点有左孩子 */
                node->parent->right = node->left;
                node->left = nullptr;
            } else {
                /* 删除结点有右孩子 */
                node->parent->right = node->right;
                node->right = nullptr;
            }
        }
        delete node;
        node = nullptr;
    } else {
        /* 删除结点度为2 */
        // 找到左子树最大的数lamx
        BSTNode<T> *lmax = maximum(node->left);
        node->data = lmax->data;
        if(node->left == lmax) {
            node->left = lmax->left;
        } else {
            lmax->parent->right = lmax->left;
        }
        lmax->left = nullptr;
        delete lmax;
        lmax = nullptr;
    }

    return true;
}

template <class T>
volatile bool BSTree<T>::deleteNode(T dst) {
    BSTNode<T>* delNode = this->searchData(dst);

    if(delNode != nullptr)
        return this->deleteNode(delNode);

    return false;
}

/*
**  摧毁二叉树
*/
template <class T>
void BSTree<T>::destroyTree(BSTNode<T>* &root) {
    if(root == nullptr)
        return ;
    if(root->left != nullptr)
        destroyTree(root->left);
    if(root->right != nullptr)
        destroyTree(root->right);

    delete root;
    root = nullptr;
    nodeSum--;
}

template <class T>
void BSTree<T>::destroyTree() {
    destroyTree(mRoot);
}

#endif // BSTREE_H