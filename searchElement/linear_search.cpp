#include <vector>
//-------------------
// CLRS linear_search
//-------------------
std::vector<int>::iterator linear_search(std::vector<int>& values, int desired)
{
	std::vector<int>::iterator it;
	for (it = values.begin(); it < values.end(); it++)
	{
		if (*it == desired)
		{
			return it;
		}
	}
	return values.end();
} // end of std::vector<int>::iterator linear_search
