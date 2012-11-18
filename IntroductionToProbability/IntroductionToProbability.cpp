#include <iostream>
#include <iterator>
#include <algorithm>

double ProbabilityOfAnIdenticalPair(double GC_context)
{
	double p_A = 0.5 * ( 1.0 - GC_context );
	double p_C = 0.5 * GC_context;
	double p_G = p_C;
	double p_T = p_A;

	return p_A * p_A + p_C*p_C + p_G*p_G + p_T*p_T;
}

int main(int argc, char* argv[])
{
	std::istream_iterator<double> eos;
	std::istream_iterator<double> in(std::cin);
      
	std::ostream_iterator<double> os(std::cout, " "); 

	std::transform(in,eos,os,[](double d)
	{
		return ProbabilityOfAnIdenticalPair(d);
	});
	std::cout<<std::endl;
}

