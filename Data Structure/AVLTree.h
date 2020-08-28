#ifndef AVLTREE_H
#define AVLTREE_H

#include "BSTree.h"

/* 平衡二叉树 */
template <class T>
class AVLTree : public BSTree<T>
{
public:
    bool isBalanced();          // 判断是否为平衡二叉树
    volatile void addNode(T newData);           // 添加结点
    volatile bool deleteNode(T dst);            // 删除指定结点
 
protected:
    bool isBalanced(BSTNode<T> *root) const;                  // 判断是否为平衡因子
    BSTNode<T> *leftRotate(BSTNode<T>* &root);      // 左旋
    BSTNode<T> *rightRotate(BSTNode<T>* &root);     // 右旋
    BSTNode<T> *leftRightRotate(BSTNode<T>* &root);     // LR旋转(先左旋再右旋)
    BSTNode<T> *rightLeftRotate(BSTNode<T>* &root);     // RL旋转(先右旋再左旋)
    volatile void addNode(BSTNode<T>* &root, BSTNode<T>* &node);    // 添加指定结点
    volatile bool deleteNode(BSTNode<T>* &node);                   // 删除指定数据

};

/**
 *  判断该结点是否为平衡因子 
 *  即 abs(depth(left) - depth(left)) <= 1
 */
template <class T>
bool AVLTree<T>::isBalanced(BSTNode<T> *root) const {
    if(root == nullptr)
        return true;
    
    int ldep = this->depth(root->left);
    int rdep = this->depth(root->right);
    if(abs(ldep - rdep) > 1)
        return false;
    else
        return isBalanced(root->left) && isBalanced(root->right);
}

template <class T>
bool AVLTree<T>::isBalanced() {
    return isBalanced(this->mRoot);
}


/**
 *  左子树深度 < 右子树深度，即 depth(right) - depth(left) > 1
 *  右边高左边低，并且 newNode->data > root->right->data，此时需要左旋
 *  (1) <-root               
 *    \                 LL          (2)
 *    (2)               =>         /   \
 *      \                        (1)   (3)   
 *      (3) <-newNode
 */
template <class T>
BSTNode<T>* AVLTree<T>::leftRotate(BSTNode<T>* &root) {
    BSTNode<T> *temp = root->right;
    root->right = temp->left;
    if(root->right != nullptr) {
        // 即如果 temp->left != nullptr
        root->right->parent = root;
    }
    temp->left = root;
    temp->parent = root->parent;
    root->parent = temp;
    return temp;
}

/**
 *  左子树深度 > 右子树深度，即 depth(left) - depth(right) > 1
 *  左边高右边低，并且 newNode->data < root->left->data，此时需要右旋
 *      (3) <-root    
 *      /               RR          (2)
 *    (2)               =>         /   \
 *    /                          (1)   (3)
 *  (1) <-newNode
 */
template <class T>
BSTNode<T>* AVLTree<T>::rightRotate(BSTNode<T>* &root) {
    BSTNode<T> *temp = root->left;
    root->left = temp->right;
    if(root->left != nullptr) {
        // 即如果 temp->right != nullptr
        root->left->parent = root;
    }
    temp->right = root;
    temp->parent = root->parent;
    root->parent = temp;
    return temp;
}

/**
 *  左子树深度 > 右子树深度，即 depth(left) - depth(right) > 1
 *  左边高右边低，并且 newNode->data > root->right->data，此时需要先左旋再右旋
 *    (3) <-root               (3)    
 *    /             LL         /         RR          (2)    
 *  (1)             =>       (2)         =>         /   \
 *    \                      /                    (1)   (3)   
 *    (2) <-newNode        (1) 
 */
template <class T>
BSTNode<T>* AVLTree<T>::leftRightRotate(BSTNode<T>* &root) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
}


/**
 *  左子树深度 < 右子树深度，即 depth(right) - depth(left) > 1
 *  右边高左边低，并且 newNode->data < root->right->data，此时需要先右旋再左旋
 *  (1) <-root             (1)    
 *    \             RR       \           LL          (2)    
 *    (3)           =>       (2)         =>         /   \
 *    /                        \                  (1)   (3)   
 *  (2) <-newNode              (3) 
 */
template <class T>
BSTNode<T>* AVLTree<T>::rightLeftRotate(BSTNode<T>* &root) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
}


/**
 *  添加结点，注意平衡因子的判断
 */
template <class T>
volatile void AVLTree<T>::addNode(BSTNode<T>* &root, BSTNode<T>* &node) {
    if(root == nullptr) {
        this->nodeSum++;
        root = node;
    } else {
        if(root->data == node->data) {
            return ;
        } else if(node->data < root->data) {
            // 往左子树插入
            this->addNode(root->left, node);
            root->left->parent = root;
            // 如果插入之后，左边高右边低 -> 需要右旋
            if(this->depth(root->left) - this->depth(root->right) >= 2) {
                if(node->data < root->left->data) {
                    // 右旋
                    root = this->rightRotate(root);
                } else {
                    // 先对其左子树左旋再右旋
                    root = this->leftRightRotate(root);
                }
            }
        } else if(node->data > root->data) {
            // 往右子树插入
            this->addNode(root->right, node);
            root->right->parent = root;
            // 如果插入之后，左边低右边高 -> 需要左旋
            if(this->depth(root->right) - this->depth(root->left) >= 2) {
                if(node->data > root->right->data) {
                    // 左旋
                    root = this->leftRotate(root);
                } else {
                    // 先对其右子树右旋再左旋
                    root = this->rightLeftRotate(root);
                }
            }
        }
    }
}

template <class T>
volatile void AVLTree<T>::addNode(T newData) {
    BSTNode<T> *newNode = nullptr;

    if(!(newNode = new BSTNode<T>(newData, nullptr, nullptr, nullptr)))
        return ;

    this->addNode(this->mRoot, newNode);
}


/**
 *  删除结点 
 */
template <class T>
volatile bool AVLTree<T>::deleteNode(BSTNode<T>* &node) {
    if(node == nullptr)
        return false;

    
}

template <class T>
volatile bool AVLTree<T>::deleteNode(T dst) {
    BSTNode<T>* delNode = this->searchData(dst);

    if(delNode != nullptr)
        return this->deleteNode(delNode);

    return false;
}


#endif // AVLTREE_H