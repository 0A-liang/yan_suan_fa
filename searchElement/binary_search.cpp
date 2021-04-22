#include <vector>
#include <iterator>
using namespace std;
using iter = std::vector<int>::iterator;

/*
	Use divide-and-conquer technique to solve the problem
*/
iter binary_search(vector<int>& values, iter low, iter high, int x)
{
	if (low <= high)
	{
		iter it;
		it = low + (high - low) / 2;
		if (x > * it)
		{
			return binary_search(values, it + 1, high, x);
		}
		else if (x < *it)
		{
			return binary_search(values, low, it - 1, x);
		}
		else
		{
			return it;
		}
	}
	else
	{
		return values.end();
	}
}

//int = iter - iter
//iter = iter + int
