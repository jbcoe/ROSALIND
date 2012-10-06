#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

int main(int argc, char* argv[])
{
	std::vector<std::string> geneStrings;
	geneStrings.reserve(10);

	std::istream_iterator<std::string> iit(std::cin);
	std::istream_iterator<std::string> eos;

	std::copy(iit,eos,std::back_inserter(geneStrings));

	auto ostream_it = std::ostream_iterator<std::string>(std::cout," ");
	std::copy(geneStrings.begin(),geneStrings.end(),ostream_it);

	std::cout << std::endl;
}

