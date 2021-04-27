#include <iostream>
#include <vector>
using namespace std;
using iter = vector<int>::iterator;
void BinarySearch(vector<int>& A, iter low, iter high, int v)
{
	for (iter it = low; it != high+1; it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	iter mid = low + (high - low) / 2;
	if (low <= high)
	{
		if (v > *mid)
		{
			BinarySearch(A, mid + 1, high, v);
		}
		else if (v < *mid)
		{
			BinarySearch(A, low, mid - 1, v);
		}
		else
		{
			cout << *mid << endl;
		}
	}
}
int main(int argc, char *argv[])
{
	vector<int> A;
	int i, n, v;
	for (cin >> i; i > 0; i--) { cin >> n; A.push_back(n); }
	cin >> v;
	BinarySearch(A, A.begin(), A.end()-1,v);
}
