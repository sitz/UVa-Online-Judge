# include <iostream>
using namespace std;

struct freq
{
       char ch;
       long int X ;
};

bool compare(freq A, freq B)
{
     if (A.X>B.X)
     return false;
     else if (A.X<B.X)
     return true;
     else return (A.ch>B.ch);
}

int main()
{
    char str[1005];
    int start=0;
    while(gets(str)!=NULL)
    {
                            
                            if (start)
                            cout<<endl;            
                            else start=1;
                            
                          freq arr[128]; int i;
    for (int  ch=0;ch<=127;ch++)
{    arr[ch].ch=ch;arr[ch].X=0;}
    
    
    for(i=0;i<strlen(str);i++)
    arr[str[i]].X++;
    sort(arr,arr+128,compare);
    for (i=0;i<128;i++)
    if (arr[i].X>0)
    cout<<(int)arr[i].ch<<" "<<arr[i].X<<endl; 
    }
return 0;
}
