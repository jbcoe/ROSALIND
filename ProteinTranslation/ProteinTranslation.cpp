#include <iostream>

struct BaseTriple
{
	char m_b1 = '\0';
	char m_b2 = '\0';
	char m_b3 = '\0';

  BaseTriple() {}

	BaseTriple (char b1, char b2, char b3) : 
		m_b1(b1), m_b2(b2), m_b3(b3) {}

	bool operator < (const BaseTriple& t) const
	{
		if ( m_b1 < t.m_b1 )
			return true;
		if ( t.m_b1 < m_b1 )
			return false;
		
		if ( m_b2 < t.m_b2 )
			return true;
		if ( t.m_b2 < m_b2 )
			return false;
		
		if ( m_b3 < t.m_b3 )
			return true;
		if ( t.m_b3 < m_b3 )
			return false;

		return false;
	}
};

char GetProtein(char b1, char b2, char b3)
{
}
int main(int argc, char* argv[])
{
}


