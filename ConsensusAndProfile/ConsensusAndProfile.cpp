#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <array>

class BaseCount
{
	public:

		BaseCount() : m_counts() {}

		void operator = (char c)
		{
			switch (c)
			{
				case 'A':
					++m_counts[0];
					break;
				case 'C':
					++m_counts[1];
					break;
				case 'G':
					++m_counts[2];
					break;
				case 'T':
					++m_counts[3];
					break;
				default:
					throw std::runtime_error("Bad base");
			}
		}

		short count(char c) const
		{
			switch (c)
			{
				case 'A':
					return m_counts[0];
					break;
				case 'C':
					return m_counts[1];
					break;
				case 'G':
					return m_counts[2];
					break;
				case 'T':
					return m_counts[3];
					break;
				default:
					throw std::runtime_error("Bad base");
			}
		}

		operator char () const
		{
			auto maxE = std::max_element(m_counts.begin(),m_counts.end());
			switch(std::distance(m_counts.begin(),maxE))
			{
				case 0:
					return 'A';
				case 1:
					return 'C';
				case 2:
					return 'G';
				case 3:
					return 'T';
				default:
					throw std::runtime_error("Bad max base index");
			}
		}

	private:
		std::array<short,4> m_counts;
};

int main(int argc, char* argv[])
{
	std::string geneString;
	std::vector<BaseCount> baseCounts;
	while( getline(std::cin,geneString) )
	{
		// Make sure our count list is long enough
		baseCounts.resize(std::max(geneString.size(), baseCounts.size()));
		std::copy(geneString.begin(),geneString.end(),baseCounts.begin());
	}

	std::array<char,4> bases{{'A','C','G','T'}};

	std::ostream_iterator<char> os(std::cout);
	std::copy(baseCounts.begin(),baseCounts.end(),os);
	std::cout << std::endl;

	std::for_each(bases.begin(),bases.end(),[&](char c)
	{                                    
		std::cout << c << ':';
		std::for_each(baseCounts.begin(),baseCounts.end(),[&](const BaseCount& bc)
		{                                    
			std::cout << ' ' << bc.count(c);
		});
		std::cout << std::endl;
	});
}

