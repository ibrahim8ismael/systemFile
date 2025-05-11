#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

    ifstream file;
    file.open("mytest.txt");

    string word;
    file >> word;

    cout << word << endl;


}