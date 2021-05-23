#include "avl.cpp"
#include <vector>
void testInsertTree(){
    vector<int> values = {9, 6, 8, 7, 13, 5, 10};
    AVLTree<int> test;
    for(auto& v : values){
        test.insert(v);
        test.printTree();
        cout << " ------------------------- " << endl;
    }
    cout << "RESULT >> ";
    for(auto& v: test.rangeQuery1D(5, 14)){
        cout << v << " ";
    }
    cout << endl;
}

int main(){
    testInsertTree();
}
