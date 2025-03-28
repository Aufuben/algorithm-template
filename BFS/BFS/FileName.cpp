/*
BFS���ص����ڷ�ɢ�������������Χ��ɢ����˲�Ҫ������Ϊ�������·���ĵ��㷨��
�����Խ�������������Χ��ɢ���㷨
*/

/*
the main code will be shown below
struct node{
	int x,y;  ��¼״̬
	int l��	  ��¼��ɢ����
	}
queue<node>q;
vector<vector<bool>>vis;
void BFS(){
	q.push((node){1,1,1});
	while(!q.empty()){
		node now=q.front();
		vis[now.x][now.y]=true;
		q.pop();
		if(�����յ����ѭ����������){
			cout<<now.l-1;�������·�����ȣ�Ҳ�����Ƿ�ɢ���״̬
			break;
			}
		for(��ѡѡ��){
			if(��֦����) continue;
			if(vis[nx][ny]==false&&���Է�ɢ������ط�) q.push((node){nx,ny,now.l+1});
			}
		}
	}
*/

/*
��Ŀ����

С����һ��յأ��������յػ���Ϊ n �� m �е�С�飬ÿ�к�ÿ�еĳ��ȶ�Ϊ 1��

С��ѡ�����е�һЩС��յأ������˲ݣ�����С����Ȼ�����ǿյء�

��Щ�ݳ��úܿ죬ÿ���£��ݶ������ⳤ��һЩ�����һ��С�����˲ݣ����������Լ����ϡ��¡�������С��յ���չ��

����С��յض�����Ϊ�вݵ�С�顣�����С����k ���º�յ�����Щ�ط��вݡ�

��������

����ĵ�һ�а����������� n,m��

������ n �У�ÿ�а��� m ����ĸ����ʾ��ʼ�Ŀյ�״̬����ĸ֮��û�пո����ΪС���㣬��ʾΪ�յأ������ĸΪ g����ʾ���˲ݡ�

����������һ������ k�� ���У�2��n,m��1000��1��k��1000��

�������

��� n �У�ÿ�а��� m ����ĸ����ʾ k ���º�յص�״̬�����ΪС���㣬��ʾΪ�յأ������ĸΪ g����ʾ���˲ݡ�
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