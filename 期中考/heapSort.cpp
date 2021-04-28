#include <iostream>
#include <vector>
using namespace std;
void swap(int &p1, int &p2)
{
	int temp = p1;
	p1 = p2;
	p2 = temp;
}
void maxHeapify1(vector<int>& A, int root, int length)
{
	for (int i = 1; i < A.size(); i++)
		cout << A[i] << " ";
	cout << endl;
	int left = 2 * root, right = 2 * root + 1, largest;
	if (left <= length && A[left] > A[root])
	{
		largest = left;
	}
	else
	{
		largest = root;
	}
	if (right <= length && A[right] > A[largest])
	{
		largest = right;
	}
	if (largest != root)
	{
		swap(A[largest], A[root]);
		maxHeapify1(A, largest, length);
	}
}
void maxHeapify(vector<int>& A, int root, int length)
{
	int left = 2 * root, right = 2 * root + 1, largest;
	if (left <= length && A[left] > A[root])
	{
		largest = left;
	}
	else
	{
		largest = root;
	}
	if (right <= length && A[right] > A[largest])
	{
		largest = right;
	}
	if (largest != root)
	{
		swap(A[largest], A[root]);
		maxHeapify(A, largest, length);
	}
}
void buildMaxHeap(vector<int>& A)
{
	for (int i = A.size() / 2; i >= 1; i--)
	{
		maxHeapify(A,i,A.size()-1);
	}
}
void heapSort(vector<int>& A)
{
	A.insert(A.begin(), 0);
	buildMaxHeap(A);
	int size = A.size() - 1;
	for (int i = A.size() - 1; i >= 2; i--)
	{
		swap(A[1], A[i]);
		size--;
		maxHeapify1(A, 1, size);
	}
	for (int i = 1; i < A.size(); i++)
		cout << A[i] << " ";
	cout << endl;
}
int main(int argc, char *argv[])
{
	vector<int> A;
	int i, n;
	for (cin >> i; i > 0; i--) { cin >> n; A.push_back(n); }
	heapSort(A);
}
