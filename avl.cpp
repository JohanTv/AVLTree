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
void AVLTree<T>::correctBalance(Node<T>* &node)
{
    int hb = getBalanceFactor(node);
    if(hb >= 2){//cargado por la izquierda
        if(getBalanceFactor(node->left) >= 1)
            rotationToRight(node);//rotacion simple
        else {//<=-1, rotacion doble izquierda-derecha
            rotationToLeft(node->left);        
            rotationToRight(node);        
        }
    }
    else if(hb <= -2){//cargado por la derecha
        if(getBalanceFactor(node->right) <= -1)
            rotationToLeft(node);//rotacion simple
        else {//>=1, rotacion doble derecha-izquierda
            rotationToRight(node->right);        
            rotationToLeft(node);
        }
    }
}

template <typename T>
void AVLTree<T>::insert(Node<T>* &node, T value){
    if(value > node->data){
        if(!node->right){
            node->right = new Node<T>(value);
            if(!node->left) node->left = new Node<T>(node->data);
        }else{
            insert(node->right, value);
        }
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        correctBalance(node);
    }else{
        if(!node->left){
            node->left = new Node<T>(value, 1);
            node->left->left = new Node<T>(value);
        }else{
            insert(node->left, value);
        }
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        correctBalance(node);
    }
}

template <typename T>
void AVLTree<T>::printTree(Node<T>* &root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    printTree(root->right, space); 
  
    // Print current node after space 
    // count 
    cout << endl; 
    for (int i = COUNT; i < space; i++) 
        cout<<" "; 
    cout << root->data << endl; 
  
    // Process left child 
    printTree(root->left, space); 
} 