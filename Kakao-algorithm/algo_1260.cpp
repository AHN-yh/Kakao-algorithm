#include "algo_1260.h"

using namespace std;

int visited[1001];
int graph[1001][1001];
int N, M;

void dfs(int v) {
	cout << v << " ";
	visited[v] = 1;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0 && graph[v][i] == 1) {
			dfs(i);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = 1;
	cout << start << " ";
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (visited[i] == 0 && graph[cur][i] == 1) {
				cout << i << " ";
				visited[i] = 1;
				q.push(i);
			}
		}
	}
}

void init() {
	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
	}
}

void solve_algo() {
	int start;
	cin >> N >> M >> start;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	cout << "Start bfs!" << endl << "-> ";
	bfs(start);
	cout << endl<< endl;

	init();
	cout << "Start dfs!" << endl << "-> ";
	dfs(start);
	cout << endl;
}