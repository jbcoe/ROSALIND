#include <iostream>
#include <iterator>
#include <algorithm>
#include <map>

struct CGCount
{
	CGCount() : count(0), cgCount(0) {}
	
	std::string name;
	int count;
	int cgCount;

	double GC_content() const
	{
		if (count==0)
			return 0.0;

		return static_cast<double>(cgCount)/static_cast<double>(count);
	}
};

static void checkAndUpdateBest(CGCount& current, CGCount& best)
{
	if ( current.GC_content() > best.GC_content() ) 
	{ 
		best = std::move(current);
	}
}

int main(int argc, char* argv[])
{
  CGCount best;
	CGCount current;

	std::string buffer;
	while ( getline(std::cin, buffer) )
	{
		if ( buffer[0] == '>' )
		{
	    checkAndUpdateBest(current,best);
			current.name = buffer.replace(0,1,"");
      current.count = 0;
			current.cgCount = 0;
		}
		else
		{
			std::for_each(buffer.begin(),buffer.end(),[&](char c)
			{
				++current.count;
				if ( c=='C' || c=='G' ) ++current.cgCount;
			});
		}
	}

	checkAndUpdateBest(current,best);
	
	std::cout << best.name << std::endl;
	std::cout << (best.GC_content() * 100.0) << "%" << std::endl;
}

