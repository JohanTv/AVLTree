#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Test{
private:
    vector<pair<int, int>> values;
    pair<int, int> p1;
    pair<int, int> p2;
    RangeTree<int> test;
    vector<pair<int, int>> response;
    string filename;
    string result_filename;

    void read(){
        ifstream file(this->filename);
        if (file.is_open()){
            int a, b;
            int nquery;
            file >> a >> b;;
            p1 = {a, b};
            file >> a >> b >> nquery;
            p2 = {a, b};
            for (int i = 0; i < nquery ; ++i){
                file >> a >> b;
                values.push_back({a,b});
            }
            file.close();
        }
    }

    void resolveQuery(){
        fstream file(this->result_filename, ios::out);
        response = test.rangeQuery2D(p1, p2);
        for(auto& v: response){
            file << "(" << v.first << "," << v.second << ")" << endl;
        }
        file.close();
    }

    void printResponse(){
        cout << "Resultados son:" << endl;
        for(int i=0; i < response.size(); ++i){
            cout << "(" << response[i].first << ", " << response[i].second << ") ";
        }
        cout << endl;
        cout << "Guardado en " << this->result_filename << endl;
    }

    void printValues(){
        cout << "La consulta es: (" << p1.first << ", " << p2.second << ") a (" << p2.first << "," << p2.second << ")" << endl;
        for(int i=0; i < values.size(); ++i){
            cout << "(" << values[i].first << ", " << values[i].second << ") ";
        }
        cout << endl;        
    }

public:
    Test() {}
    Test(string filename){ this->filename = filename; this->result_filename = "result_"+filename; }
    void runTest(){
        read();
        printValues();
        test.build2DRangeTree(values);
        resolveQuery();   
        printResponse();
    }
};