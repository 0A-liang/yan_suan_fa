#include <iostream>
#include <vector>
using namespace std;
using iter = vector<int>::iterator;
void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void selectionSort(vector<int>& A)
{
	for (iter it = A.begin(); it != A.end()-1; it++)
	{
		iter min = it;
		for (iter it2 = it + 1; it2 != A.end(); it2++)
		{
			if (*it2 < *min)
			{
				min = it2;
			}
		}
		swap(*min,*it);
		for (iter itr = A.begin(); itr != A.end(); itr++)
		{
			cout << *itr << " ";
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
