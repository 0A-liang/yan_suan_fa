#include <iostream>
#include <vector>
using namespace std;
using iter = vector<int>::iterator;
int LinearSearch(vector<int>& A, int v)
{
	int count=0;
	for (iter it = A.begin(); it != A.end(); it++)
	{
		if (*it == v)
		{
			return count;
		}
		else
		{
			count++;
		}
	}
	return -1;
}
int main(int argc, char *argv[])
{
	vector<int> A;
	int i, n, v;
	for (cin >> i; i > 0; i--) { cin >> n; A.push_back(n); }
	cin >> v;
	cout << LinearSearch(A, v) << endl;
}
