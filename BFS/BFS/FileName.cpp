/*
BFS的特点在于发散，从起点逐步向周围发散，因此不要局限他为搜索最短路径的的算法，
而可以将其视作逐步向周围发散的算法
*/

/*
the main code will be shown below
struct node{
	int x,y;  记录状态
	int l；	  记录发散次数
	}
queue<node>q;
vector<vector<bool>>vis;
void BFS(){
	q.push((node){1,1,1});
	while(!q.empty()){
		node now=q.front();
		vis[now.x][now.y]=true;
		q.pop();
		if(到达终点或者循环结束条件){
			cout<<now.l-1;输出的是路径长度，也可以是发散后的状态
			break;
			}
		for(备选选项){
			if(剪枝条件) continue;
			if(vis[nx][ny]==false&&可以发散到这个地方) q.push((node){nx,ny,now.l+1});
			}
		}
	}
*/

/*
题目描述

小明有一块空地，他将这块空地划分为 n 行 m 列的小块，每行和每列的长度都为 1。

小明选了其中的一些小块空地，种上了草，其他小块仍然保持是空地。

这些草长得很快，每个月，草都会向外长出一些，如果一个小块种了草，则它将向自己的上、下、左、右四小块空地扩展，

这四小块空地都将变为有草的小块。请告诉小明，k 个月后空地上哪些地方有草。

输入描述

输入的第一行包含两个整数 n,m。

接下来 n 行，每行包含 m 个字母，表示初始的空地状态，字母之间没有空格。如果为小数点，表示为空地，如果字母为 g，表示种了草。

接下来包含一个整数 k。 其中，2≤n,m≤1000，1≤k≤1000。

输出描述

输出 n 行，每行包含 m 个字母，表示 k 个月后空地的状态。如果为小数点，表示为空地，如果字母为 g，表示长了草。
*/
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