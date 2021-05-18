#include "node.h"
#define COUNT 10

template <typename T>
class AVLTree{
private:
    Node<T>* root;
    int getHeight(Node<T>* &node);
    int getBalanceFactor(Node<T>* & node);
    void rotationToLeft(Node<T>* &parent);
    void rotationToRight(Node<T>* &parent);
    void correctBalance(Node<T>* &node);
    void insert(Node<T>* &node, T value);
    void printTree(Node<T>* &root, int space);

public:
    AVLTree() : root(nullptr) {}
    void insert(T value){
        insert(this->root, value);
    }
    void printTree(){
        printTree(this->root, 0);
    }
};