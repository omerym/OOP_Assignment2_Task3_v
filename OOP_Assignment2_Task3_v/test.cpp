#include <iostream>
using namespace std;
int main()
{
    unsigned short x=0x11EF;
    unsigned char pos= (x&0x0f00)>>8;
    unsigned char y=(x &0x00ff);
    int reg[16];
    int ram[256];
    ram[239]=8;
    reg[(unsigned char)pos]=ram[(unsigned char)y];
    unsigned char output=reg[1];
    cout<<hex<<+output;
    cin>>x;
}