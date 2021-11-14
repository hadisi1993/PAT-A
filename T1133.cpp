#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Node{
	int addr, data, next;
}node[100005];
int b, n, k;
int main()
{
	cin >> b >> n >> k;
	vector<Node>v;
	int addr, data, next;
	for (int i = 0; i<n; i++){
		cin >> addr >> data >> next;
		node[addr] = { addr, data, next };
	}
	for (int i = b; i != -1; i = node[i].next){
		if (node[i].data<0) v.push_back(node[i]);
	}
	for (int i = b; i != -1; i = node[i].next){
		if (node[i].data >= 0 && node[i].data <= k) v.push_back(node[i]);
	}
	for (int i = b; i != -1; i = node[i].next){
		if (node[i].data>k) v.push_back(node[i]);
	}
	for (int i = 0; i<v.size(); i++){
		if (i != v.size() - 1) printf("%05d %d %05d\n", v[i].addr, v[i].data, v[i + 1].addr);
		else printf("%05d %d -1\n", v[i].addr, v[i].data);
	}
	return 0;
}
