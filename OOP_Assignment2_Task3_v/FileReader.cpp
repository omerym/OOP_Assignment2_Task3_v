#include<iostream>
#include "MemoryUnit.cpp"
using namespace std;
class FileReader {
private:
    istream* input;
public:
    FileReader(istream* input)
    {
        this->input = input;
    }
    void read(MemortUnit* omer) {
        int i = 0;
        while (input && i < omer->size())
        {

            int c;
            (*input) >> hex >> c;
            *(omer->at(i)) = c;
            i++;
        }
    }
};
