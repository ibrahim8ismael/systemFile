#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(){

    ifstream file;
    file.open("mytest.txt");

    char s;
    while(!(file.eof())){ //eof mean the end of text
        // file >> s;
        file.get(s); // no skip with spaces
        if(file.fail()){
            break;
        }
        cout << s << endl;
    }

}