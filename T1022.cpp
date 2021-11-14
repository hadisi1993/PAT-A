#include <iostream>
#include<string>
#include<set>
#include<map>
#include<sstream>
using namespace std;
map<string, set<string> >mptitle, mpauthor, mpkey, mppub, mpyear;
void query(map<string, set<string> >&mp, string&str)
{
	if (mp.find(str) == mp.end())
		cout << "Not Found" << endl;
	else
	{
		for (set<string>::iterator it = mp[str].begin(); it != mp[str].end(); it++)
			cout << *it << endl;
	}
}
int main()
{
	int n, m, type;
	string ID, author, title, publisher, year, key, temp;
	//freopen("input.txt","r",stdin);
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cin >> ID;
		getchar();
		getline(cin, title);
		mptitle[title].insert(ID);
		getline(cin, author);
		mpauthor[author].insert(ID);
		getline(cin, key);
		stringstream ss(key);
		string temp;
		while (ss >> temp)
			mpkey[temp].insert(ID);
		getline(cin, publisher);
		mppub[publisher].insert(ID);
		getline(cin, year);
		mpyear[year].insert(ID);
	}
	cin >> m;
	for (int i = 0; i<m; i++)
	{
		scanf("%d: ", &type);
		getline(cin, temp);
		cout << type << ": " << temp << endl;
		switch (type)
		{
		case 1:query(mptitle, temp); break;
		case 2:query(mpauthor, temp); break;
		case 3:query(mpkey, temp); break;
		case 4:query(mppub, temp); break;
		case 5:query(mpyear, temp); break;
		default:break;
		}
	}
	return 0;
}
