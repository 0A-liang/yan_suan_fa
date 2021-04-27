#include <iostream>
#include <vector>
using namespace std;
void BinarySearch(vector<int>& A, int low, int high, int v)
{
	for (int i=low;i<high+1;i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	int mid = low + (high - low) / 2;
	if (low <= high)
	{
		if (v > A[mid])
		{
			BinarySearch(A, mid + 1, high, v);
		}
		else if (v < A[mid])
		{
			BinarySearch(A, low, mid - 1, v);
		}
		else
		{
			cout << A[mid] << endl;
		}
	}
}
int main(int argc, char *argv[])
{
	vector<int> A;
	int i, n, v;
	for (cin >> i; i > 0; i--) { cin >> n; A.push_back(n); }
	cin >> v;
	BinarySearch(A, 0, A.size()-1,v);
}
