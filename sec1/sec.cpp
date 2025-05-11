#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ofstream file; //new object
    file.open("mytest.txt"); // Create the file and link with object
    file << "Welcome to here in my mac";  // write into my file
    file.close(); // close my file

}