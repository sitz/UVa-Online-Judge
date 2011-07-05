#include<stdio.h>

int main()
{
    int n,i;
    scanf("%d",&n);
    char s[10];
    for(i=0;i<n;i++)
                    scanf("%s",s);
                    char *a = s;
                    perm(a,strlen(a)-1,0);
                    printf("")
    return 0;
}


void swap(char *p,char *q)
{
 char c;
 c=*p;
 *p=*q;
 *q=c;
}



void perm(char *a,int m,int n)
{
   if(m==n)
   {
           for(int i=0;i<=n;i++)
           cout<<a[i];
   }
   else
   {
           for(int j=n;j<=m;j++)
           {
                   swap(a[j],a[n]);
                   perm(a,m,n+1);
                   swap(&a[j],&a[n]);
           }

   }
}          



