#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>

int main()
{
	std::string dna1;
	getline(std::cin,dna1);

	std::string dna2;
  getline(std::cin,dna2);

	int hammingDistance = 0;
	
  auto it_1 = dna1.begin();
  auto it_2 = dna2.begin();
  auto dna_end = dna1.end();
  
	if(dna1.size()<dna2.size())
    dna_end = dna2.end();

  for ( ; it_1 != dna_end; ++it_1, ++it_2 )
	{
		if ( *it_1 != * it_2 ) ++hammingDistance;
	}

	std::cout << hammingDistance << std::endl;
}
