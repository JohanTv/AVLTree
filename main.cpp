#include "avl.cpp"
#include <vector>
void testInsertTree(){
    vector<pair<int, int>> values = {{9,2}, {6,5}, {6,4}, {6,8}, {13,1}, {5,12}, {3,3}};
    RangeTree<int, int> test;
    for(auto& v : values){
        test.insert(v);
        // test.printTree();
        // cout << " ------------------------- " << endl;
    }
    cout << "RESULT >> ";
    for(auto& v: test.rangeQuery2D({5, 3}, {8,9})){
        cout << v << " ";
    }
    cout << endl;
}

int main(){
    testInsertTree();
}
