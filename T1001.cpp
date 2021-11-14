#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int c =a+b;
    if(c<0) printf("-");
    if(abs(c)>=1e6)
        printf("%d,%03d,%03d",abs(c)/1000000,(abs(c)/1000)%1000,abs(c)%1000);
    else if(abs(c)>=1e3)
        printf("%d,%03d",(abs(c)/1000)%1000,abs(c)%1000);
    else
        printf("%d",abs(c)%1000);
    return 0;
}
