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
    Node<T>* findClosest(Node<T>* &node, T value);


public:
    AVLTree() : root(nullptr) {}

    Node<T>* findSplitNode(T min, T max);
    Node<T>* RangeQuery1D(T min, T max);
    
    void insert(T value){
        if(this->root) insert(this->root, value);
        else this->root = new Node<T>(value);
    }
    Node<T>* find(T value){
        if(this->root) return findClosest(this->root, value);
        else return nullptr;
    }
    void printTree(){
        printTree(this->root, 0);
    }
};
