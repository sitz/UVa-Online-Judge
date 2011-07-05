#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string arr[100], str;
    while(getline(cin,str)){
                                   int N=0;
                                   arr[N++]= str;
                                   while(true){
                                               getline(cin, str);
                                               if(str=="")
                                                           break;
                                                arr[N++]=str;
                                   }
                                   for(int i=0;i<N; i++)
                                           cout<<arr[i]<<endl;
    }
    return 0;
}
