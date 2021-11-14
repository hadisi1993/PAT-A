#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int num[105],maxlevel = -1;
vector<int>ch[105];
void dfs(int node,int l)
{
    if(!ch[node].size())
    {
        num[l]++;
        maxlevel = max(maxlevel,l);
    }
    for(int i=0;i<ch[node].size();i++)
        dfs(ch[node][i],l+1);
}
int main()
{
    int n,m,id,k,c;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&id,&k);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&c);
            ch[id].push_back(c);
        }
    }
    dfs(1,0);
    for(int i=0;i<=maxlevel;i++)
        i==0?printf("%d",num[i]):printf(" %d",num[i]);
    return 0;
}
