#include "avl.cpp"
#include <vector>
void testInsertTree(){
    vector<int> values = {6, 8, 9};
    AVLTree<int> test;
    for(auto& v : values){
        test.insert(v);
    }
    test.printTree();
}

int main(){
    testInsertTree();
}