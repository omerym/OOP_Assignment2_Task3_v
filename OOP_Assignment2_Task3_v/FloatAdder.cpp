#ifndef _FloatAdder
#define _FloatAdder
static class FloatAdder
{
public:
	static int toInt(unsigned char num)
	{
		int r = 0;
		int sign = (0b10000000 & num) >> 7;
		int mantissa = (0b00001111 & num);
		int exp = (0b01110000 & num) >> 4;
		r |= mantissa;
		r <<= exp;
		return sign == 0 ? r : -r;
	}	
};

#endif