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
    //cout << test.find(11)->data;
    cout << "SPLIT NODE >> ";
    cout << test.findSplitNode(8, 14)->data << endl;
}

int main(){
    testInsertTree();
}
