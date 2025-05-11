#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(){

    ifstream file;
    file.open("mytest.txt");

    string line;
    while(getline(file,line)){
        cout<< line << endl;
    }

}