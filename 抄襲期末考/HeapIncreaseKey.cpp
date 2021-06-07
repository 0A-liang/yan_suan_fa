#include <iostream>
#include <vector>
using namespace std;
using iter = vector<int>::iterator;
int Parent(int i)
{
	return (i - 1) / 2;
}
void HeapIncreaseKey(vector<int>& A, int i, int key)
{
	if (key < A[i])
		throw "new key is smaller than current key";
	A[i] = key;
	while (i > 0 && A[Parent(i)] < A[i])
	{
		swap(A[i], A[Parent(i)]);
		i = Parent(i);
	}
	for (iter it = A.begin(); it != A.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main(int argc, char *argv[])
{
	vector<int> A;
	int i, n, key;
	for (cin >> i; i > 0; i--) { cin >> n; A.push_back(n); }
	cin >> i >> key;
	HeapIncreaseKey(A, i, key);
}
