#include <iostream>
#include <vector>
using namespace std;
int LinearSearch(vector<int>& A, int v)
{
	int count=0;
	for (int i=0;i<A.size();i++)
	{
		if (A[i] == v)
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
