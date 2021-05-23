#include "avl.h"
#include <iostream>

using namespace std;

template <typename T>
int AVLTree<T>::getHeight(Node<T>* &node){
    if(node) return node->height;
    return -1;
}

template <typename T>
int AVLTree<T>::getBalanceFactor(Node<T>* &node){
    return getHeight(node->left) - getHeight(node->right);
}

template <typename T>
void AVLTree<T>::rotationToLeft(Node<T>* &parent){
    Node<T>* temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    parent = temp;
    parent->left->height = max(getHeight(parent->left->left), getHeight(parent->left->right)) + 1;
    parent->height = max(getHeight(parent->left), getHeight(parent->right)) + 1;
}

template <typename T>
void AVLTree<T>::rotationToRight(Node<T>* &parent){
    Node<T>* temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    parent = temp;
    parent->right->height = max(getHeight(parent->right->left), getHeight(parent->right->right)) + 1;
    parent->height = max(getHeight(parent->left), getHeight(parent->right)) + 1;
}

template <typename T>
void AVLTree<T>::correctBalance(Node<T>* &node){
    int hb = getBalanceFactor(node);
    if(hb >= 2){
        if(getBalanceFactor(node->left) >= 1)
            rotationToRight(node);
        else {
            rotationToLeft(node->left);
            rotationToRight(node);
        }
    }else if(hb <= -2){
        if(getBalanceFactor(node->right) <= -1)
            rotationToLeft(node);
        else {
            rotationToRight(node->right);
            rotationToLeft(node);
        }
    }
}
template <typename T>
Node<T>* AVLTree<T>::findClosest(Node<T>* &node, T value){
    if(value > node->data){
        if(node->right && node->left){
            cout << node->data - node->left->data << " - ";
            cout << node->right->leftmost()->data - node->data << endl;
            if(node->data - node->left->data >= node->right->leftmost()->data - node->data)
                return findClosest(node->right, value);
            else return findClosest(node->left, value);
        }
    }else{
        if(node->left){
 //       if(node->data - node->left->data > node->right->data - node->data)
 //         return findClosest(node->right, value);
            return findClosest(node->left, value);
        }
    }
    return node;
}

template<typename T>
Node<T>* AVLTree<T>::findSplitNode(T min, T max){
    Node<T>* temp = this->root;
    while(temp->height != 0 and (max <= temp->data || temp->data < min)){
        if(max <= temp->data) temp = temp->left;
        else temp = temp->right;
    }
    return temp;
}

template<typename T>
Node<T>* AVLTree<T>::RangeQuery1D(T min, T max){
    Node<T>* splitNode = findSplitNode(min, max);
}

template <typename T>
void AVLTree<T>::insert(Node<T>* &node, T value){
    if(value > node->data){
        if(!node->right){
            node->right = new Node<T>(value);
            node->left = new Node<T>(node->data);
        }else
            insert(node->right, value);
    }else{
        if(!node->left){
            node->left = new Node<T>(value, 1);
            node->left->left = new Node<T>(value);
        }else
            insert(node->left, value);
    }
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    correctBalance(node);
}

template <typename T>
void AVLTree<T>::printTree(Node<T>* &root, int space){
    if (root == NULL) 
        return;
    space += COUNT;
    printTree(root->right, space);
    cout << endl; 
    for (int i = COUNT; i < space; i++) 
        cout<<" "; 
    cout << root->data << endl;
    printTree(root->left, space); 
} 
