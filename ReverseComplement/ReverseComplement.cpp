#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>

int main()
{
	std::istream_iterator<char> eos;
	std::istream_iterator<char> iit (std::cin);

	std::vector<char> bases;

	std::copy(iit,eos,std::back_inserter(bases));

	std::transform(bases.begin(), bases.end(), bases.begin(), [](char c)->char
	{
		switch (c)
		{
		case 'A':
			return 'T';
		case 'T':
			return 'A';
		case 'C':
			return 'G';
		case 'G':
			return 'C';
		}

		return '-';
	});
  
	std::ostream_iterator<char> out_it (std::cout,"");

	std::copy(bases.rbegin(),bases.rend(),out_it);

	std::cout << std::endl;
}
