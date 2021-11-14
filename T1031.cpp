#include <iostream>
#include<string.h>
using namespace std;
/*这道题采用填充字符数组的方式做一遍*/
int main()
{
	char c[81], u[30][30];
	memset(u, ' ', sizeof(u));
	scanf("%s", c);
	int n = strlen(c) + 2;
	int h = n / 3, w = n / 3 + n % 3, index = 0;
	for (int i = 0; i<h; i++) u[i][0] = c[index++];
	for (int i = 1; i<w - 1; i++) u[h - 1][i] = c[index++];
	for (int i = h - 1; i >= 0; i--) u[i][w - 1] = c[index++];
	for (int i = 0; i<h; i++){
		for (int j = 0; j<w; j++)
			printf("%c", u[i][j]);
		printf("\n");
	}
	return 0;
}
