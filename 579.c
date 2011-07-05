#include<stdio.h>

int main()
{
    int h[1000],m[1000],n=0,i=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
                     scanf("%d:%d\n",&h[i],&m[i]);         
    if(h[i]==12 && m[i]==00)
         {
                h[i]=12;
                m[i]=00;
         }
    else if(h[i]==12 && m[i]!=00)
         h[i]=11;         
    else if(h[i]==06 && m[i]==30)
         {
                     h[i]=06;
                     m[i]=30;  
         }
    else if(h[i]<<11)
               h[i]=11-h[i];
    else if(h[i]=11)
         h[i]=12;
     
    
    m[i]=60-m[i];
    if(m[i]==60)
                m[i]=00;
    }
    
    for(i=0;i<n;i++)
    {
                     printf("%2.2d:%2.2d\n",h[i],m[i]);
    }
    
    return 0;
}
         
    
