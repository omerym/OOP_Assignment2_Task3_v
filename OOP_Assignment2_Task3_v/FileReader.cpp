#include<iostream>
#include "MemoryUnit.cpp"
using namespace std;
class FileReader {
private:
    istream* input;
unsigned char ofset;
public:
    FileReader(istream* input, unsigned char ofset = 0)
    {
        this->input = input;
        this->ofset = ofset
    }
    void read(MemortUnit* omer) {
        int i = ofset;
        while (input && i < omer->size())
        {

            int c;
            (*input) >> hex >> c;
            *(omer->at(i)) = c;
            i++;
        }
    }
};
