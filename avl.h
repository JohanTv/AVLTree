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
    void insert(Node<T>* &node, pair<T,T> value, int dimensionNumber);
    void printTree(Node<T>* &root, int space);
    Node<T>* findSplitNode(Node<T>* treeRoot, T min, T max, int dimensionNumber);
    vector<pair<T,T>> reportSubtree(Node<T>* node);
    vector<pair<T,T>> rangeQuery1D(Node<T>* treeRoot, T min, T max);
    vector<pair<T,T>> rangeQuery2D(Node<T>* treeRoot, pair<T,T> xrange, pair<T,T> yrange);
    Node<T>* build2DRangeTreeUtil(vector<pair<T, T>>& pointSet);
    bool compare(pair<T,T> a, pair<T,T> b);
public:
    RangeTree() : root(nullptr){}
    
    void insert(T value){
        if(this->root) insert(this->root, value);
        else this->root = new Node<T>(value);
    }
    
    void printTree(){
        printTree(this->root, 0);
    }
    vector<pair<T,T>> rangeQuery2D(pair<T,T> a, pair<T,T> b){
        return rangeQuery2D(this->root, {a.first, b.first} , {a.second, b.second});
    }
    void build2DRangeTree(vector<pair<T, T>>& pointSet);
    
    Node<T>* getRoot(){
        return this->root;
    }
    void setRoot(Node<T>* root){
        this->root = root;
    }
};
