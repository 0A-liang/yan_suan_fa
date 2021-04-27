#include <iostream>
#include <vector>
using namespace std;
void InsertionSort(vector<int>& A)
{
	for (int i=1;i<A.size();i++)
	{
		int key = A[i];
		int j = i - 1;
		while (j>=0&&key<A[j])
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
		for (int k=0;k<A.size();k++)
		{
			cout << A[k] << " ";
		}
		cout << endl;
	}
}
int main(int argc, char *argv[])
{
	vector<int> A;
	int i, n;
	for (cin >> i; i > 0; i--) { cin >> n; A.push_back(n); }
	InsertionSort(A);
}
