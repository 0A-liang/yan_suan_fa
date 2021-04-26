#include <iostream>
#include <vector>
using namespace std;
using iter = vector<int>::iterator;
void InsertionSort(vector<int>& A)
{
	for (iter it = A.begin() + 1; it != A.end(); it++)
	{
		int key = *it;
		iter it2 = it - 1;
		while (it2>=A.begin()&&key<*it2)
		{
			*(it2 + 1) = *it2;
			it2--;
		}
		*(it2 + 1) = key;
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
	InsertionSort(A);
}
