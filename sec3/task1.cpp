#include <iostream>
#include <fstream>

using namespace std;
int main(){
    ifstream file1;
    file1.open("example.txt");

    ofstream file2;
    file2.open("example1.txt");

    char ch;
    while(file1.get(ch)){
        file2.put(ch);
    }

    file1.close();
    file2.close();
}