#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char* argv[])
{
	std::string genome;
	getline(std::cin, genome);
	
	std::string motif;
	getline(std::cin, motif);

	auto it_genome = genome.begin();
	auto end_genome = genome.end();

	auto motif_length = motif.size();

  if ( motif_length > genome.size() )
	{	
		std::cout << std::endl;
		return -1;
	}

	for ( ; it_genome + motif_length != end_genome; ++it_genome )
	{
     if ( std::equal(motif.begin(),motif.end(),it_genome) )
		 {
			 std::cout << 1+std::distance(genome.begin(), it_genome) << ' ';
		 }
	}
	std::cout << std::endl;
}

