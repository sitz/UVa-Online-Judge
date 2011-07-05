#include<iostream>
using namespace std;
int main(){
    int test;
    cin>>test;
    while(test--){
                  string str;
                  cin>>str;
                  int len=str.length(),period=0,allStr[150]={0},i=0;
                  for(i=0;i<len;i++){
                                     allStr[str[i]-'\0']++;
                  }
                  int min=100;
                  for(i=0;i<150;i++){
                                     if(allStr[i]>0)
                                                    min=(min<allStr[i])?min:allStr[i];
                  }
                  for(i=0;i<150;i++){
                                     if(allStr[i]>0 && min!=0)
                                                    period+=(allStr[i]/min);
                  }
                  cout<<period;
                  if(test>0)
                            cout<<endl<<endl;
    }
    system("pause");
    return 0;
}
