#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    for(;;){
            int i,n;
            scanf("%d",&n);
            if(n==0)
                    break;
            char ch=getchar();
                             string toReplace[n],replaceBy[n],str;
                             for(i=0;i<n;i++){
                                              getline(cin,toReplace[i]);
                                              getline(cin,replaceBy[i]);
                             }
                             getline(cin,str);
                             for(i=0;i<n;i++){
                                              size_t found;
                                              found=str.find(toReplace[i]);
                                              while(found!=string::npos){
                                                      str.replace((int)found,toReplace[i].length(),replaceBy[i]);
                                                      found=str.find(toReplace[i]);
                                              }
                             }
                             cout<<str<<endl;
    }
    return 0;
}
