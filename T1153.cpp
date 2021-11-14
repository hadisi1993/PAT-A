#include <iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<map>
using namespace std;
struct Card{
	string ori;
	string level;
	string site;
	string date;
	string testNum;
	int score;
	Card(string card, int score){
		this->ori = card;
		this->level = card.substr(0, 1);
		this->site = card.substr(1, 3);
		this->date = card.substr(4, 6);
		this->testNum = card.substr(10, 3);
		this->score = score;
	}
};
vector<Card>v;
bool cmp1(Card a, Card b){
	return a.score == b.score ? a.ori<b.ori : a.score>b.score;
}
void output1(int s, string term){
	printf("Case %d: 1 %s\n", s, term.c_str());
	int cnt = 0;
	for (int i = 0; i<v.size(); i++){
		if (v[i].level == term){
			printf("%s %d\n", v[i].ori.c_str(), v[i].score);
			cnt++;
		}
	}
	if (cnt == 0) printf("NA\n");
}

void output2(int s, string term){
	printf("Case %d: 2 %s\n", s, term.c_str());
	int sum = 0, cnt = 0;
	for (int i = 0; i<v.size(); i++){
		if (v[i].site == term){
			cnt++;
			sum += v[i].score;
		}
	}
	if (cnt == 0){
		printf("NA\n");
		return;
	}
	printf("%d %d\n", cnt, sum);
}
bool cmp2(pair<string, int>a, pair<string, int>b){
	return a.second == b.second ? a.first<b.first : a.second>b.second;
}
void output3(int s, string term){
	printf("Case %d: 3 %s\n", s, term.c_str());
	unordered_map<string, int>m;
	vector<pair<string, int>>dv;
	int cnt = 0;
	for (int i = 0; i<v.size(); i++){
		if (v[i].date == term){
			m[v[i].site]++;
			cnt++;
		}
	}
	for (auto it : m){
		dv.push_back(it);
	}
	sort(dv.begin(), dv.end(), cmp2);
	for (int i = 0; i<dv.size(); i++){
		printf("%s %d\n", dv[i].first.c_str(), dv[i].second);
	}
	if (cnt == 0) printf("NA\n");
}
int main()
{
	int n, k;
	cin >> n >> k;
	string tmp;
	int score;
	for (int i = 0; i<n; i++){
		cin >> tmp >> score;
		v.push_back(Card(tmp, score));
	}
	sort(v.begin(), v.end(), cmp1);
	int type;
	string term;
	for (int i = 0; i<k; i++){
		cin >> type >> term;
		switch (type){
		case 1:output1(i + 1, term); break;
		case 2:output2(i + 1, term); break;
		case 3:output3(i + 1, term); break;
		}
	}
	return 0;
}
