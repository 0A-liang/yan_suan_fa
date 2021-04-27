#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int>& A)
{
	for (int i=A.size()-1;i>0;i--)
	{
		for (int j=0;j<i;j++)
		{
			if (A[j] > A[j+1])
			{
				int temp = A[j];
            			A[j] = A[j+1];
            			A[j+1] = temp;
				for (int k=0;k<A.size();k++)
				{
					cout << A[k] << " ";
				}
				cout << endl;
			}
		}
	}
}
int main(int argc, char *argv[])
{
	vector<int> A;
	int i, n;
	for (cin >> i; i > 0; i--) { cin >> n; A.push_back(n); }
	bubbleSort(A);
}
