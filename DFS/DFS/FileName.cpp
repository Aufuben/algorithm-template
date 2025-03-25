/*
the main code structure will be shown below

void DFS(参数列表){			这主要是根据题目要求，一般n维就有n个参数
	----- 1. 终止条件判断（必须首先处理）-----
	if(到达递归终点,无法继续搜索下一层){
		if(符合题目要求){
			judge=true;
			return;
			}
		return;
		}
	----- 2. 生成所有可能选择（遍历决策树）-----
	for(所有候选选项){
		如路径问题：遍历四个方向：
			const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  这一行放在全局的位置
			则决策树为for(int i=0;i<4;i++){
						int nx=x+dirs[i][0];
						int ny=y+dirs[i][1];
							}
		也可以是排列组合问题，思路大概相同
	----- 3. 剪枝操作（在状态修改前进行）-----
		if(越界||重复选取) continue;
		if(提前可以终止无效路径) continue;
	----- 4. 状态修改（进入下一层前的操作）-----
		根据问题类型修改状态，进行状态转移
		标记已经访问
		记录当前的选择
		vis[i]=true;
		path.push_back(i);
	----- 5. 递归进入下一层-----
		DFS(新的参数);
		if(judge) return;
	----- 6. 回溯恢复状态（关键对称操作）-----
		必须与步骤4完全对称
		弹出最后元素
		取消访问标记
		path.pop_back();
		vis[i]=false
*/

/*
题目描述

小明冒充 X 星球的骑士，进入了一个奇怪的城堡。

城堡里边什么都没有，只有方形石头铺成的地面。

假设城堡地面是 n×n 个方格。

按习俗，骑士要从西北角走到东南角。可以横向或纵向移动，但不能斜着走，也不能跳跃。每走到一个新方格，就要向正北方和正西方各射一箭。（城堡的西墙和北墙内各有 n 个靶子）同一个方格只允许经过一次。但不必走完所有的方格。如果只给出靶子上箭的数目，你能推断出骑士的行走路线吗？

本题的要求就是已知箭靶数字，求骑士的行走路径（测试数据保证路径唯一）

输入描述

第一行一个整数 N (0≤N≤20)，表示地面有 N×N 个方格。

第二行 N 个整数，空格分开，表示北边的箭靶上的数字（自西向东）

第三行 N 个整数，空格分开，表示西边的箭靶上的数字（自北向南）

输出描述

输出一行若干个整数，表示骑士路径。

为了方便表示，我们约定每个小格子用一个数字代表，从西北角开始编号: 0,1,2,3 ⋯⋯

比如，图中的方块编号可以为：

0 1 2 3

4 5 6 7

8 9 10 11

12 13 14 15
*/
#include <iostream>
#include <vector>
using namespace std;
int n;
bool judge = false;
const int dire[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
vector<int>north; vector<int>west;
vector<int>path;
vector<vector<bool>>vis ;
vector<int>curnorth; vector<int>curwest;
void DFS(int x, int y) {
	if (x == n - 1 && y == n - 1) {
		if (curnorth == north && curwest == west) {
			judge = true;
			return;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dire[i][0];
		int ny = y + dire[i][1];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n || curwest[nx] >= west[nx] || curnorth[ny] >= north[ny]||vis[nx][ny]) continue;
		curnorth[ny]++;
		curwest[nx]++;
		vis[nx][ny] = true;
		path.push_back(nx * n + ny);
		DFS(nx, ny);
		if (judge) return;
		path.pop_back();
		vis[nx][ny] = false;
		curwest[nx]--;
		curnorth[ny]--;
	}
}
int main() {
	cin >> n;
	north.resize(n, 0); west.resize(n, 0);
	curnorth.resize(n, 0); curwest.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> north[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> west[i];
	}
	vis.resize(n, vector<bool>(n, false));
	vis[0][0] = true; curnorth[0]++; curwest[0]++; path.push_back(0);
	DFS(0, 0);
	for (int i = 0; i < path.size(); i++) {
		cout << path[i]<<" ";
	}
	return 0;


/*
题目描述
	已知n个盒子，第i个盒子有i个宝石，每个宝石有重量wi和价值ci，求在这些宝石取最大质量不超过m的最大价值的方案
*/

/*
dfs代码示例
void dfs(int pos,long long nowcost,long long lastw){
	if(pos==n||lastw<=0) return;
	ans = max(ans,nowcost);
	for(int i=a[pos].num;i>=0;i--){
		dfs(pos+1,nowcost+i*a[pos].c,lastw-i*a[pos].w);
		}
}
略去剪枝，其实DFS的核心就在于状态转移和状态定义
*/