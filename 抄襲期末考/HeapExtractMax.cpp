#include <iostream>
#include <vector>
using namespace std;
using iter=vector<int>::iterator;
void MaxHeapify(vector<int>& A, int root)
{
	int left = (root + 1) * 2 - 1, right = (root + 1) * 2, largest;
	if (left <= A.size()-1 && A[left] > A[root])
	{
		largest = left;
	}
	else
	{
		largest = root;
	}
	if (right <= A.size()-1 && A[right] > A[largest])
	{
		largest = right;
	}
	if (largest != root)
	{
		swap(A[largest], A[root]);
		MaxHeapify(A, largest);
	}
}
int HeapExtractMax(vector<int>& A,int heap_size)
{
	if (heap_size < 0)
		throw "heap underflow";
	int max = A[0];
	A[0]=A[heap_size-1];
	MaxHeapify(A,0);
	return max;
}
void printVector(vector<int>& A)
{
	for (iter it = A.begin(); it != A.end()-1; it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main(int argc, char *argv[])
{
	vector<int> A;
	int i, n;
	for (cin >> i; i > 0; i--) { cin >> n; A.push_back(n); }
	cout << HeapExtractMax(A,A.size()) << endl;
	printVector(A);
}
