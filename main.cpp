#include "avl.cpp"
#include <vector>
void testInsertTree(){
    vector<int> values = {9, 6, 8, 7, 13};
    AVLTree<int> test;
    for(auto& v : values){
        test.insert(v);
        test.printTree();
        cout << " ------------------------- " << endl;
    }
}

int main(){
    testInsertTree();
}