#include <iostream>
using namespace std;
int N;
int G[100][100];
int Visited[100]={};
int Queue[100];
int front = -1, rear = -1;
void BFS(int i)
{
    rear++;
	Queue[rear] = i;
	Visited[i] = 1;
	while (front < rear)
	{
		int node = Queue[++front];
		cout << node << " ";
		for (int j = 0; j <= N; j++)
		{
			if (G[node][j] && !Visited[j])
			{
			    rear++;
				Queue[rear] = j;
				Visited[j] = 1;
			}
		}
	}
}
int main(int argc, char *argv[])
{
	int i,E;
	cin >> N >> E >> i;
	int v1, v2;
	for (int j = 0; j < E; j++)
	{
		cin >> v1 >> v2;
		G[v1][v2] = 1;
		G[v2][v1] = 1;
	}
	BFS(i);
}
