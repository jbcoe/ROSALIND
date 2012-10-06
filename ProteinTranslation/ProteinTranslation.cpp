#include <stdexcept>                    
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>

int IndexOfBase(char c)
{
	switch(c)
	{
		case 'U':
			return 0;
		case 'C':
			return 1;
		case 'A':
			return 2;
		case 'G':
			return 3;
		default:
			throw std::runtime_error("Bad base");
	}
}

const char* const codonToAcid = 
"FFLL"
"SSSS"
"YYss"
"CCsW"
"LLLL"
"PPPP"
"HHQQ"
"RRRR"
"IIIM"
"TTTT"
"NNKK"
"SSRR"
"VVVV"
"AAAA"
"DDEE"
"GGGG";

int main()
{
	std::istream_iterator<char> eos;
	std::istream_iterator<char> iit (std::cin);

	std::map<char,int> baseCount;

	while ( iit != eos )
	{
		char b1 = *iit++;
		if ( iit == eos )
			break;

		char b2 = *iit++;
		if ( iit == eos )
			break;

		char b3 = *iit++;
		if ( iit == eos )
			break;

		char amminoAcid = codonToAcid[
			16*IndexOfBase(b1) + 
			4*IndexOfBase(b2) + 
			IndexOfBase(b3)];

		if ( amminoAcid == 's' )
			break;

		std::cout << amminoAcid;
	}

	std::cout << std::endl;
}

