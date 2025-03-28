#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, k;
const int dire[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
vector<vector<char>>v;
struct node {
	int x, y;
	int l;
};
vector<vector<bool>>vis;
queue<node>q;
void BFS() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 'g') {
				q.push({ i, j ,0 });
				vis[i][j] = true;
			}
		}
	}
	while (!q.empty()) {
		node now = q.front();
		vis[now.x][now.y] = true;
		q.pop();
		if (now.l < k) {
			for (int i = 0; i < 4; i++) {
				int nx = now.x + dire[i][0];
				int ny = now.y + dire[i][1];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == false && v[nx][ny] == '.') {
					v[nx][ny] = 'g';
					q.push({ nx, ny, now.l + 1 });
					vis[nx][ny] = true;
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	vis.resize(n, vector<bool>(m, false));
	v.resize(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	cin >> k;
	BFS();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << v[i][j];
		}
		cout << endl;
	}
	return 0;
}