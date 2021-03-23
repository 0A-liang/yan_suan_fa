#include <algorithm>
#include "algorithm.h"
#include <iostream>
void insertion_sort(vector<int>& A)
{
	vector<int>::iterator it;
	for (int i = 1; i < A.size(); i++)
	{
		int key = A[i];
		int j = i - 1;
		while (key < A[j] && j >= 0)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
	for (it = A.begin(); it != A.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
} // end of insertion_sort


void selection_sort(vector<int>& A)
{
	vector<int>::iterator it;

	for (int i = 0; i < A.size(); i++)
	{
		for (int j = i + 1; j < A.size(); j++)
		{
			if (A[i]>A[j])
			{
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
	for (it = A.begin(); it != A.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
} // end of selection_sort


void bubble_sort(vector<int>& A)
{
	vector<int>::iterator it;
	vector<int>::iterator it2;
	for (it = A.begin(); it != A.end(); it++)
	{
		for (it2 = A.begin(); it2 != A.end()-1; it2++)
		{
			if (*it2 > *(it2 + 1))
			{
				int temp = *it2;
				*it2 = *(it2 + 1);
				*(it2 + 1) = temp;
			}
		}
	}
	for (it = A.begin(); it != A.end(); it++)
		cout << *it << " ";
}
int linear_search(vector<int>& A, int v)
{
	vector<int>::iterator it;
	for (it = A.begin(); it != A.end(); ++it) {
		if (*it == v) {
			return it - A.begin();
		}
	} // end of for
	return -1;
} // end of linear_search

int std_search_default(vector<int>& A, int v)
{
	vector<int> B = { v };
	vector<int>::iterator it;
	it = std::search(A.begin(), A.end(), B.begin(), B.end());

	if (it != A.end())
		return it - A.begin();
	else
		return -1;
}
bool mypredicate(int i, int j)
{
	return (i == j);
}
int std_search_predicate(vector<int>& A, int v)
{
	vector<int> B = { v };
	vector<int>::iterator it;
	it = std::search(A.begin(), A.end(), B.begin(), B.end(), mypredicate);

	if (it != A.end())
		return it - A.begin();
	else
		return -1;
}

int std_find(vector<int>& A, int v) {
	vector<int>::iterator it;
	it = std::find(A.begin(), A.end(), v);

	if (it != A.end())
		return it - A.begin();
	else
		return -1;
}
