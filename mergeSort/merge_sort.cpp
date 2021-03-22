#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
using namespace std;
void merge(vector<int>& A, size_t p, size_t q, size_t r)
{
	size_t n1, n2 , i, j, k;
	n1 = q - p + 1;
	n2 = r - q;
	vector<int> L(n1 + 1);
	vector<int> R(n2 + 1);
	for (i = 0; i < n1; i++)
		L[i] = A[p + i];
	for (j = 0; j < n2; j++)
		R[j] = A[q + j + 1];
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	i = 0;
	j = 0;
	for (k = p; k <= r; k++)
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
	}
}
void merge_sort(vector<int>& A, size_t p, size_t r)
{
	if (p < r)
	{
		size_t q = static_cast<size_t>(floor((p + r) / 2.0)) + 1;
		merge_sort(A, p, q - 1);
		merge_sort(A, q, r);
		merge(A, p, q - 1, r);
	}
}
TEST_CASE("merge sort are computed", "[merge_sort]")
{
	vector<int> values = { 3, 5, 1, 4, 2 };
	vector<int> result1 = { 1, 2, 3, 4, 5 };
	vector<int> result2 = { 1, 3, 2, 4, 5 };
	merge_sort(values, 0, values.size() - 1);
	REQUIRE(values == result1);
	REQUIRE(values == result2);
}
