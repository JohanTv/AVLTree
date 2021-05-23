#include "avl.cpp"
#include <vector>
void testInsertTree(){
    vector<pair<int, int>> values = {{9,2}, {6,5}, {6,4}, {6,8}, {13,1}, {5,12}, {3,3}};
    RangeTree<int> test;
    test.build2DRangeTree(values);
    cout << "RESULT >> ";
    for(auto& v: test.rangeQuery2D({0,0}, {100,100})){
        cout << v.first << "-" << v.second << " ";
    }
    cout << endl;
}

int main(){
    testInsertTree();
}
