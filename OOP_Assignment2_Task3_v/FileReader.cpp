#include<iostream>
#include "MemoryUnit.cpp"
#include <bits/stdc++.h>
using namespace std;
class FileReader{
    private:
    istream *input;
    public:
    FileReader(istream * input){
        this -> input = input;
        
    }   
    ifstream iff;
    
    void read(MemortUnit* omer){
        for(int i =0;i<256;i++){
            if (!iff.eof()) {
                cout << "The file is not finished." << endl;
                
                } break;
            int c;
            (*input)>>hex>>c;
            omer->set(i,c);
            
            
        }
    }
    
   
};
void print( MemortUnit* omrt){
    for(int i = 0;i<256;i++){
        cout<<hex<<(int)(omrt->get(i))<<endl;
    }
};
int main(){
    char bn[] = "C:\\Users\\Abdallah\\Desktop\\bashar";
    ifstream iff;
    iff.open(bn);
    int s = 3;
    unsigned char * ya= new unsigned char(5);
    FileReader fr(&iff);
    fr.read(ya,s);
    print(ya,s);
    return 0; 


}