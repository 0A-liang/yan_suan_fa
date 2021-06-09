#include <iostream>
using namespace std;
int N;
int Gnode[100][2];
int Visited[100] = {};
int G[100][100];
void DFS(int i)
{
	Visited[i] = 1;
	cout << i + 1 << " ";
	for (int j = 0; j <= N - 1; j++)
	{
		if (G[i][j] == 1)
		{
			if (Visited[j] != 1)
				DFS(j);
		}
	}
}
int main(int argc, char *argv[])
{
	int i, E;
	int connect1, connect2;
	cin >> N >> E >> i;
	for (int j = 0; j < E; j++)
	{
		cin >> connect1 >> connect2;
		Gnode[j][0] = connect1;
		Gnode[j][1] = connect2;
	}
	int R_node;
	for (int row = 0; row <= N - 1; row++)
	{
		for (int column = 0; column <= N - 1; column++)
		{
			G[row][column] = 0;
		}
	}
	for (int row = 0; row <= E - 1; row++)
	{
		R_node = Gnode[row][0] - 1;
		for (int column = 0; column <= 1; column++)
		{
			G[R_node][Gnode[row][column] - 1] = 1;
		}
	}
	for (int row = 0; row <= N - 1; row++)
	{
		for (int column = 0; column <= N - 1; column++)
		{
			if (row == column)
				G[row][column] = 0;
		}
	}
	for (int row = 0; row <= E - 1; row++)
	{
		R_node = Gnode[row][1] - 1;
		for (int column = 0; column <= 1; column++)
		{
			G[R_node][Gnode[row][column] - 1] = 1;
		}
	}
	DFS(i - 1);
}
