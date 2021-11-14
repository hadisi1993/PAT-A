#include<iostream>
using namespace std;
char r[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C' };
int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("#%c%c%c%c%c%c", a<12 ? r[0] : r[a / 13], r[a % 13], b<12 ? r[0] : r[b / 13], r[b % 13], c<12 ? r[0] : r[c / 13], r[c % 13]);
	return 0;
}
