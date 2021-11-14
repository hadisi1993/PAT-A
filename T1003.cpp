#include<iostream>
#include<algorithm>
using namespace std;
int edge[510][510];
int dis[510];
int vis[510];
int pathnum[510];
int maxpeo[510];
int n,m,st,ed;
int peo[510];
const int inf = 99999999;
int maxdis;
int main()
{
    fill(edge[0],edge[0]+510*510,inf);
    fill(dis,dis+510,inf);
    scanf("%d %d %d %d",&n,&m,&st,&ed);
    for(int i=0;i<n;i++)
        scanf("%d",&peo[i]);
    int v1,v2,v;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&v1,&v2,&v);
        edge[v1][v2] = v;
        edge[v2][v1] = v;
    }
    dis[st] = 0;
    pathnum[st] = 1;
    maxpeo[st] = peo[st];
    for(int i=0;i<n;i++)
    {
        maxdis = inf;
        int k=-1;
        for(int j=0;j<n;j++)
        {
            if(!vis[j])
            {
                if(dis[j]<maxdis)
                {
                    maxdis = dis[j];
                    k = j;
                }
            }
        }
        vis[k] = 1;
        if(k==-1)
            break;
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&&dis[j]>=dis[k]+edge[j][k])
            {
                if(dis[j]>dis[k]+edge[j][k])
                {
                    dis[j] = dis[k]+edge[j][k];
                    pathnum[j] = pathnum[k];
                    maxpeo[j] = maxpeo[k]+peo[j];
                }
                else
                {
                    pathnum[j]+=pathnum[k];
                    if(maxpeo[j]<=maxpeo[k]+peo[j])
                    {
                        maxpeo[j] = maxpeo[k]+peo[j];
                    }
                }
            }
        }
    }
    printf("%d %d\n",pathnum[ed],maxpeo[ed]);
    return 0;
}
