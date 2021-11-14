#include <iostream>
using namespace std;
struct term{
  int exp;
  float cof;
}t1[15],t2[15],t3[15];
int main()
{
   int k1,k2;
   scanf("%d",&k1);
   for(int i=0;i<k1;i++)
   {
       scanf("%d %f",&t1[i].exp,&t1[i].cof);
   }
   scanf("%d",&k2);
   for(int i=0;i<k2;i++)
   {
       scanf("%d %f",&t2[i].exp,&t2[i].cof);
   }
   int i=0,j=0,k=0;  //指针
   while(i<k1&&j<k2)
   {
       if(t1[i].exp>t2[j].exp)
       {
           t3[k].cof = t1[i].cof;
           t3[k].exp = t1[i].exp;
           i++;
           k++;
       }
       if(t1[i].exp<t2[j].exp)
       {
           t3[k].cof = t2[j].cof;
           t3[k].exp = t2[j].exp;
           j++;
           k++;
       }
       if(t1[i].exp==t2[j].exp)
       {
           if(t1[i].cof+t2[j].cof!=0)
           {
               t3[k].cof = t1[i].cof+t2[j].cof;
               t3[k].exp = t1[i].exp;
               k++;
           }
           i++,j++;
       }
   }
   while(i<k1)
   {
        t3[k].cof = t1[i].cof;
        t3[k].exp = t1[i].exp;
        i++;
        k++;
   }
    while(j<k2)
   {
        t3[k].cof = t2[j].cof;
        t3[k].exp = t2[j].exp;
        j++;
        k++;
   }
   printf("%d",k);
   for(int i=0;i<k;i++)
   {
       printf(" %d %.1f",t3[i].exp,t3[i].cof);
   }
   printf("\n");
   return 0;
}