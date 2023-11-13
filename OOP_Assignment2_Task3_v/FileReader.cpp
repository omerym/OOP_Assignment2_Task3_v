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
    
    void read(MemortUnit* omer){
        int i = 0;
        while(input && i < omer->size())
            {
                
            int c;
            (*input)>>hex>>c;
            *(omer->at(i)) = c;
                i++;
            }
        }
    
   
};
void print( MemortUnit* omrt){
    for(int i = 0;i<omrt->size();i++){
        cout<<hex<<(int)(omrt->get(i))<<endl;
    }
};
int main(){
   
    char bn[] = "C:\\Users\\Abdallah\\Desktop\\bashar.txt";
    ifstream iff;
    iff.open(bn);
    MemortUnit test(5,NULL);
    FileReader fr(&iff);
    cout<<"first memory";
    print(&test);
    cout<<"second memory";
    fr.read(&test);
    print(&test);
    return 0; 


}
