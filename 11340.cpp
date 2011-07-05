#include<iostream>
using namespace std;
int main(){
    int test;
    scanf("%d\n",&test);
    while(test--){
                  int n,m,i,j,k;
                  scanf("%d\n",&n);
                  char chars[n];
                  double value[n];
                  double amount=0.0;
                  for(i=0;i<n;i++)
                                   scanf("%c%lf\n",&chars[i],&value[i]);
                  scanf("%d\n",&m);
                  for(i=0;i<m;i++){
                                   string str;
                                   getline(cin,str);
                                   int len=str.length();
                                   for(j=0;j<len;j++){
                                           for(k=0;k<n;k++){
                                                   if(str[j]==chars[k]){
                                                             amount+=value[k];
                                                             break;
                                                   }
                                           }
                                   }
                  }
                  printf("%.2lf$\n",amount/100.0);
    }
    return 0;
}
