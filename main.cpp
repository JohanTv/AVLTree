#include "RangeTree.cpp"
#include "Test.h"
#include <vector>

int main(){
    Test test1("dataset100.txt");
    Test test2("dataset1000.txt");
    test1.runTest();
    test2.runTest();
}