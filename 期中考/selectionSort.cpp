#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<int>& A)
{
	for (int i=0;i<A.size()-1;i++)
	{
		int min = i;
		for (int j=i+1;j<A.size();j++)
		{
			if (A[j] < A[min])
			{
				min = j;
			}
		}
		int temp = A[min];
	    	A[min] = A[i];
	    	A[i] = temp;
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
	selectionSort(A);
}
