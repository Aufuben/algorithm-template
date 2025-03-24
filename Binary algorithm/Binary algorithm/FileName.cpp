/*
	the main body will be shown below;
	int l=-1,r=N         针对一段为0~N-1的数组
	while(l+1!=r){        结束标志为蓝色区域（小于目标值）和红色区域（大于目标值）首尾相接
		int m=(l+r)/2;	  整数二分
		if(check(m)){     核心在于check函数的定义，到底是更新l还是m要根据题目
			l=m;
			}
		else r=m;
		}
	return l or m

*/

/*
问题描述

	儿童节那天有 K 位小朋友到小明家做客。小明拿出了珍藏的巧克力招待小朋友们。

	小明一共有 N 块巧克力，其中第 i 块是 Hi×Wi 的方格组成的长方形。为了公平起见，

	小明需要从这 N 块巧克力中切出 K 块巧克力分给小朋友们。切出的巧克力需要满足：

		形状是正方形，边长是整数;

		大小相同;

	例如一块 6×5 的巧克力可以切出 6 块 2×2 的巧克力或者 2 块 3×3 的巧克力。

	当然小朋友们都希望得到的巧克力尽可能大，你能帮小明计算出最大的边长是多少么？
	输入描述

	第一行包含两个整数 N,K(1≤N,K≤10**5)。

	以下 N 行每行包含两个整数 Hi,Wi​ (1≤Hi,Wi≤10**5)。

	输入保证每位小朋友至少能获得一块 1x1 的巧克力。

输出描述

	输出切出的正方形巧克力最大可能的边长。
*/

/*
解析：
	二分本质上就是枚举，一种效率比较高的枚举方法，通过每次判断枚举的数是否满足题意来
更新下一次枚举的范围，使得最终的数为最优符合要求解
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int n, k;
vector<int>h(100002); vector<int>w(100002);//也可以用pair，struct
bool check(int x) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum >= k) break;
		if (x <= h[i] && x <= w[i]) {
			int temp = (h[i] / x) * (w[i]/x);    //一块巧克力最多能切出的数目
			sum += temp;
		}
		else continue;
	}
	if (sum >= k) return true;
	else return false;
}
int main() {
	cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> h[i] >> w[i];
		}
		int l = -1, r = 100000;
		while (l + 1 != r) {
			int mid = (l + r )/2;
			if (check(mid)) {
				l = mid;
			}
			else r = mid;
		}
		cout << l;
		return 0;
}
/*
评价
	这道题比较基础，下面会有一道进阶的
*/

/*
题目描述

小明公司的办公区有一条长长的走廊，由 N 个方格区域组成，如下图所示。

走廊内部署了 K 台扫地机器人，其中第 i 台在第 Ai 个方格区域中。已知扫地机器人每分钟可以移动到左右相邻的方格中，并将该区域清扫干净。

请你编写一个程序，计算每台机器人的清扫路线，使得

	它们最终都返回出发方格，

	每个方格区域都至少被清扫一遍，

	从机器人开始行动到最后一台机器人归位花费的时间最少。

注意多台机器人可以同时清扫同一方块区域，它们不会互相影响。

输出最少花费的时间。 在上图所示的例子中，最少花费时间是 6。第一台路线：2-1-2-3-4-3-2，清 扫了 1、2、3、4 号区域。第二台路线 5-6-7-6-5，清扫了 5、6、7。第三台路线 10-9-8-9-10，清扫了 8、9 和 10。
输入描述

第一行包含两个整数 N,K。

接下来 K 行，每行一个整数 Ai​。

其中，1≤K<N≤10**5，1≤Ai≤N1≤K<N≤10**5，1≤Ai​≤N。

输出描述

	输出一个整数表示答案。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
vector<int>a;
bool check(int x) {           //check比较直观的路程，时间等于(路程-1)*2
	int now = 0;
	for (int i = 0; i < k; i++) {
		if (a[i] - x <= now) {
			if (a[i] <= now) {
				now = a[i] + x-1;
			}
			else now += x;
		}
	}
	if (now >= n) return true;
	else return false;
}
int main() {
	cin >> n >> k;
	a.resize(k);
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int l = -1, r = 100001;
	while (l + 1 != r) {
		int mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid;
	
	}
	cout << (r-1)*2;
	return 0;
}