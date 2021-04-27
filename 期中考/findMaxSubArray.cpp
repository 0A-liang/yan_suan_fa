#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;
void findMaxSubArray(vector<int>& A)
{
	int sum, low, high;
	int currentSum, currentLow, currentHigh;
	sum = -INT_MAX;
	currentSum = -INT_MAX;
	for (int i = 0; i < A.size(); i++)
	{
		currentHigh = i;
		if (currentSum <= 0)
		{
			currentLow = i;
			currentSum = A[i];
		}
		else
		{
			currentSum = currentSum + A[i];
		}
		if (currentSum > sum)
		{
			sum = currentSum;
			low = currentLow;
			high = currentHigh;
		}
	}
    cout << low << " " << high << " " << sum << endl;
}
int main(int argc, char *argv[])
{
	vector<int> A;
	int i, n;
	for (cin >> i; i > 0; i--) { cin >> n; A.push_back(n); }
	findMaxSubArray(A);
}
