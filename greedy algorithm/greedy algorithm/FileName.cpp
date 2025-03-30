/*
̰���㷨һ�㰴���²�����У�

�ٽ�����ѧģ������������   

�ڰ���������ֳ����ɸ�������   

�۶�ÿ����������⣬�õ�������ľֲ����Ž�   

�ܰ�������Ľ�ֲ����Ž�ϳ�ԭ���������һ����   
����ڶ��������ʱ�����������ڵ�ǰ��������õ�ѡ��Ҳ����˵���������������ϼ��Կ��ǣ��㷨�õ�������ĳ�������ϵľֲ����Ž� ��
*/
/*
the main code will be shown below;
�����������ڿ�ѡ��Χ��Ѱ������ѡ��
int findbest (const vector<int>&v,int start,int end){
	int best_pos=start;
	for(int i=start;i<=end;i++){
		if(v[i]����v[start]){
			best_pos=i;
		}
	}
	return best_pos;
}
̰�������̣���������Ҫ���һ��������洢������ѡ�񼯺�
vector<int> greedyselection(const vector<int>&v,int m){
	vector<int>result;
	int n=v.size();
	int start=0;
	int remain=m;
	for(int i=0;i<m;i++){
		int end=n-remain;   //end�Ķ�����ֶ����������Ϊһ�ֿ���
		int best=findbest(v,start,end);
		result.push_back(best);
		start=best+1;
		remain--;
	}
	return result;
}
ע��̰���㷨�Ľṹ����ڱ�ĸ���������Ҳ��������˼��
*/
/*
С��Ҫ��֯һ̨��ᣬ�ܹ�׼���� n ����Ŀ��Ȼ������ʱ�����ޣ���ֻ������ѡ�����е� m ����Ŀ��

�� n ����Ŀ�ǰ���С�������˳������ģ�˳���ܸı䡣

С�����֣����ڶ������ϵ�ϲ���̶���ǰ������Ŀ�ĺÿ��̶��зǳ���Ĺ�ϵ����ϣ��ѡ���ĵ�һ����Ŀ�����ܺÿ����ڴ�ǰ����ϣ���ڶ�����Ŀ�����ܺÿ����������ơ�

С����ÿ����Ŀ������һ���ÿ�ֵ���������С��ѡ��� m ����Ŀ����������Ҫ��
��������

����ĵ�һ�а����������� n,m����ʾ��Ŀ��������Ҫѡ���������

�ڶ��а��� n ������������Ϊÿ����Ŀ�ĺÿ�ֵ��
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
��Ŀ����

����һ�����ʣ������ڵ�����ɾ�� t ����ĸ���ܵõ����ֵ�����С�ĵ�����ʲô��

��������

����ĵ�һ�а���һ�����ʣ��ɴ�дӢ����ĸ��ɡ�

�ڶ��а���һ�������� t��

���У����ʳ��Ȳ����� 100��t С�ڵ��ʳ��ȡ�

�������

���һ�����ʣ���ʾ�𰸡�
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