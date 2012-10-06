#include <iostream>
#include <algorithm>
#include <iterator>

int main()
{
	std::istream_iterator<char> eos;
	std::istream_iterator<char> iit (std::cin);

	std::for_each(iit, eos, [&](const char c)
	{
		if ( c == 'T')
			std::cout << 'U';
		else
			std::cout << c;
	});

	std::cout << std::endl;

}
