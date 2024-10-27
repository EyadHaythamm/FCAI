#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Register {
    string value;
public:
    Register(string v):value("00"){}
    void SetValue(string v) {
        value=v;
    }
    string getvalue() {
        return value;
    }
};
class Memory {
    string size;
    string value;
public:
    Memory(string v):value("00"){}
    void SetValue(string v){
        value=v;
    }
    string GetValue() {
        return value;
    }
};
class Machine {
    int registersNumber=16;
    int MemorySize=256;
public:
    Machine() {
        vector<Register> Registers[16];
        vector<Memory> MemorySize[256];
    }

};




int main() {
    ifstream inputfile;
    int spaces=0;
    string filename, contents;
    string hex1 = "";
    vector<string> lines;

    cout<<"Please enter the file name: ";

    getline(cin, filename);
    if(!"C:\\Users\\eyadl\\CLionProjects\\untitled\\"+inputfile.is_open()) {
        cout<<"File does not exist"<<endl;
    }
    inputfile.open(filename,ios::in);
    while(getline(inputfile,contents)) {
        for(int i = 0; i < contents.length(); i++) {
            if(contents[i]==' ') {
                spaces++;
            }
            if(contents[i] == 'x') {
                hex1+=contents[i+1];

            }if(contents[i]=='x'&&spaces==2) {
                hex1+=contents[i+2];
                spaces=0;
            }

        }

        lines.push_back(hex1);
        hex1 = "";

    }for(int i=0;i<lines.size();i++) {
        cout<<lines[i]<<endl;
    }

}

