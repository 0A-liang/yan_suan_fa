#include <iostream>
#include <vector>
using namespace std;
using iter = vector<int>::iterator;
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void bubbleSort(vector<int>& A)
{
	for (iter it = A.end()-1; it != A.begin(); it--)
	{
		for (iter it2 = A.begin(); it2 != it; it2++)
		{
			if (*it2 > *(it2 + 1))
			{
				swap(*(it2 + 1), *it2);
				for (iter it3 = A.begin(); it3 != A.end(); it3++)
				{
					cout << *it3 << " ";
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
