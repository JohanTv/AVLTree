#include "node.h"
#define COUNT 10
#include <vector>

template <typename T>
class RangeTree{
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
    std::vector<T> rangeQuery1D(Node<T>* treeRoot, T min, T max);
    std::vector<T> rangeQuery2D(Node<T>* treeRoot, pair<T,T> xrange, pair<T,T> yrange);

public:
    RangeTree() : root(nullptr){}
    
    void insert(T value){
        if(this->root) insert(this->root, value);
        else this->root = new Node<T>(value);
    }
    
    void printTree(){
        printTree(this->root, 0);
    }
    std::vector<T> rangeQuery1D(T min, T max);
    std::vector<T> rangeQuery2D(T min, T max);

    Node<T>* getRoot(){
        return this->root;
    }
};
