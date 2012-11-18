#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int tailfac(int i, int tail=1)
{
	if ( i == 1 )
		return tail;
	return tailfac(i-1, tail*i);
}

void ListPermutations(int perm)
{
	std::vector<int> integers(perm);
	int i=1;
	std::generate(integers.begin(),integers.end(),[&i](){return i++;});
	std::ostream_iterator<int> os(std::cout," ");

	
	while(1)
	{
		std::copy(integers.begin(),integers.end(),os);
		std::cout << std::endl;
	
		auto it_k = integers.end();
		auto it_l = integers.end();

		for( auto it = integers.begin(); it+1!=integers.end(); ++it)
		{
			if ( *it < *(it+1) ) it_k = it;
		}

		if ( it_k == integers.end() )
			return;

		for( auto it = it_k+1; it!=integers.end(); ++it)
		{
			if ( *it_k < *it ) it_l = it;
		}
	
		std::iter_swap(it_k,it_l);
		std::reverse(it_k+1,integers.end());
	}
}

int main(int argc, char* argv[])
{
	int perm;
	std::cin >> perm;
	if ( perm <1 || perm >7 )
	{
		std::cerr << "Bad input: must be in the interval [1,7]" << std::endl;
		return 1;
	}

	std::cout << tailfac(perm) << std::endl;
	ListPermutations(perm);
}

