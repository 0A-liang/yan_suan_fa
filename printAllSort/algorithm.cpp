#include <algorithm>
#include "algorithm.h"
#include <iostream>
#include <cmath>
void insertion_sort(vector<int>& A)
{
	for (int i = 1; i < A.size(); i++)
	{
		int key = A[i];
		int j = i - 1;
		while (j >= 0 && key < A[j])
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
} // end of insertion_sort

void selection_sort(vector<int>& A)
{
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = i + 1; j < A.size(); j++)
		{
			if (A[i] > A[j])
			{
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
} // end of selection_sort

void bubble_sort(vector<int>& A)
{
	vector<int>::iterator it;
	vector<int>::iterator it2;
	for (it = A.end(); it != A.begin(); it--)
	{
		for (it2 = A.begin(); it2 != A.end() - 1; it2++)
		{
			if (*it2 > *(it2 + 1))
			{
				int temp = *it2;
				*it2 = *(it2 + 1);
				*(it2 + 1) = temp;
			}
		}
	}
}
void merge(vector<int> & A, size_t p, size_t q, size_t r)
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
}
void merge_called(vector<int> & A)
{
	int first = 1;
	int last = A.size();
	merge_sort(A, first, last);
}
void merge_sort(vector<int> & A, int p, int r)
{
	if (p < r)
	{
		size_t q = static_cast<size_t>(floor((p + r) / 2.0)) + 1;
		merge_sort(A, p, q - 1);
		merge_sort(A, q, r);
		merge(A, p, q - 1, r);
	}
}

void build_heap(vector<int> & A)
{
	int n = A.size();
	for (int i = n / 2 - 1; i >= 0; i--) {
		int l, r, largest = -1;
		while (largest != i) {
			largest = i;
			l = 2 * i + 1;
			r = 2 * i + 2;
			if (l < n && A[l] > A[largest]) largest = l;
			if (r < n && A[r] > A[largest]) largest = r;
			if (largest != i) swap(A[i], A[largest]);
		}
	}
}

void heap_sort(vector<int>& A)
{
	build_heap(A);
	A.insert(A.begin(), 0);
	for (int i = A.size() - 1; i > 0; i--)
	{
		swap(A[i], A[1]);
		int current = 1;
		int tail = i;
		while (current < tail)
		{
			int left = current * 2;
			int right = current * 2 + 1;
			int max = current;
			if (left < tail && A[left] > A[max])
			{
				max = left;
			}
			else if (right < tail && A[right] > A[max])
			{
				max = right;
			}
			if (max != current)
			{
				swap(A[current], A[max]);
				current = max;
			}
			else
			{
				break;
			}
		}
	}
	A.erase(A.begin());
}
