#include "node.h"
#define COUNT 10
#include <vector>
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
    Node<T>* findSplitNode(T min, T max);
    std::vector<T> reportSubtree(Node<T>* node);

public:
    AVLTree() : root(nullptr) {}

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
    std::vector<T> rangeQuery1D(T min, T max);
};
