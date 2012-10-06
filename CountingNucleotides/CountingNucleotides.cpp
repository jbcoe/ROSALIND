#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>

int main()
{
	std::istream_iterator<char> eos;
	std::istream_iterator<char> iit (std::cin);

	std::map<char,int> baseCount;

	std::for_each(iit, eos, [&](const char c)
			{
			++baseCount[c];
			});

	for ( const auto& kv : baseCount )
	{
		std::cout << kv.second << " ";
	}
	std::cout << std::endl;
}
