/*
贪心算法一般按如下步骤进行：

①建立数学模型来描述问题   

②把求解的问题分成若干个子问题   

③对每个子问题求解，得到子问题的局部最优解   

④把子问题的解局部最优解合成原来解问题的一个解   
因此在对问题求解时，总是做出在当前看来是最好的选择。也就是说，不从整体最优上加以考虑，算法得到的是在某种意义上的局部最优解 。
*/
/*
the main code will be shown below;
辅助函数：在可选范围内寻找最优选择
int findbest (const vector<int>&v,int start,int end){
	int best_pos=start;
	for(int i=start;i<=end;i++){
		if(v[i]优于v[start]){
			best_pos=i;
		}
	}
	return best_pos;
}
贪心主流程：假设我们要输出一个用数组存储的最优选择集合
vector<int> greedyselection(const vector<int>&v,int m){
	vector<int>result;
	int n=v.size();
	int start=0;
	int remain=m;
	for(int i=0;i<m;i++){
		int end=n-remain;   //end的定义多种多样，这里仅为一种可能
		int best=findbest(v,start,end);
		result.push_back(best);
		start=best+1;
		remain--;
	}
	return result;
}
注：贪心算法的结构相较于别的更加灵活，但是也更加容易思考
*/
/*
小明要组织一台晚会，总共准备了 n 个节目。然后晚会的时间有限，他只能最终选择其中的 m 个节目。

这 n 个节目是按照小明设想的顺序给定的，顺序不能改变。

小明发现，观众对于晚上的喜欢程度与前几个节目的好看程度有非常大的关系，他希望选出的第一个节目尽可能好看，在此前提下希望第二个节目尽可能好看，依次类推。

小明给每个节目定义了一个好看值，请你帮助小明选择出 m 个节目，满足他的要求。
输入描述

输入的第一行包含两个整数 n,m，表示节目的数量和要选择的数量。

第二行包含 n 个整数，依次为每个节目的好看值。
*/
#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int>v;
int main() {
	cin >> n >> m;
	v.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int start = 0;
	int remain = m;
	vector<int>result;
	for (int i = 0; i < m; i++) {
		int end = n - remain;
		int best = start;
		for (int j = start; j <= end; j++) {
			if (v[j] > v[best]) best = j;
		}
		remain--;
		start = best + 1;
		result.push_back(v[best]);
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
	return 0;
}
/*
题目描述

给定一个单词，请问在单词中删除 t 个字母后，能得到的字典序最小的单词是什么？

输入描述

输入的第一行包含一个单词，由大写英文字母组成。

第二行包含一个正整数 t。

其中，单词长度不超过 100，t 小于单词长度。

输出描述

输出一个单词，表示答案。
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int t;
int main()
{
	string s; cin >> s;
	cin >> t;
	int start = 0;
	int remain = s.size() - t;
	vector<char>res;
	for (int i = 0; i < s.size() - t; i++) {
		int end = s.size() - remain;
		int choice = start;
		for (int j = start; j <= end; j++) {
			if (s[j] < s[choice]) choice = j;
		}
		res.push_back(s[choice]);
		start = choice + 1;
		remain--;
	}
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
	}
	return 0;
}