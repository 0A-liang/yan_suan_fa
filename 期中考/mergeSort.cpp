#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
void mergeSort(vector<int> & A, size_t p, size_t q, size_t r)
{
	size_t n1, n2;
	n1 = q - p + 1;
	n2 = r - q;
	vector<int> L(n1 + 1);
	vector<int> R(n2 + 1);
	for (int i = 0; i < n1; i++)
		L[i] = A[p + i];
	for (int j = 0; j < n2; j++)
		R[j] = A[q + j + 1];
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	int resetLeft = 0;
	int resetRight = 0;
	for (int k = p; k <= r; k++)
	{
		if (L[resetLeft] <= R[resetRight])
		{
			A[k] = L[resetLeft];
			resetLeft++;
		}
		else
		{
			A[k] = R[resetRight];
			resetRight++;
		}
	}
	for(int i=0;i<A.size();i++)
	{
	    cout<<A[i]<<" ";
	}
	cout<<endl;
}
void merge(vector<int> & A, int p, int r)
{
	if (p < r)
	{
		size_t q = static_cast<size_t>(floor((p + r) / 2.0)) + 1;
		merge(A, p, q - 1);
		merge(A, q, r);
		mergeSort(A, p, q - 1, r);
	}
}
int main(int argc, char *argv[])
{   
    vector<int> A;
	int i, n;
	for(cin >> i; i > 0; i--) { cin >> n; A.push_back(n); }
	merge(A,0,A.size()-1);
}
