#include<iostream>
using namespace std;
int tsize, n, hashtable[10100];
bool isprime(int num)
{
	if (num == 1) return false;
	for (int i = 2; i * i <= num; i++)
	if (num % i == 0) return false;
	return true;
}
void insert(int key)
{
	for (int step = 0; step<tsize; step++)
	{
		int index = (key + step*step) % tsize;
		if (hashtable[index] == 0)
		{
			hashtable[index] = 1;
			cout << index%tsize;
			return;
		}
	}
	cout << '-';
}
int main()
{
	cin >> tsize >> n;
	while (!isprime(tsize))
		tsize++;
	for (int i = 0; i<n; i++)
	{
		int key;
		cin >> key;
		if (i)
			cout << " ";
		insert(key);
	}
	return 0;
}
