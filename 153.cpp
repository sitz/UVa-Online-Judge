#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    for(;;){
            char str[30];
            cin>>str;
            if(str=="#")
                        break;
            string init=str;
            int len=sizeof(str);
            for(int i=0;i<len;i++){
                    for(int j=i+1;j<len;j++){
                            if(str[i]>str[j]){
                                              char temp=str[i];
                                              str[i]=str[j];
                                              str[j]=temp;
                            }
                    }
            }
            int count=0;
            do{
                    count++;
                    string s;
                    for(int k=0;k<len;k++)
                            s+=str[k];
                    if(str==init)
                                 break;
            }while(next_permutation(str,str+len));
            printf("%10d",count);
    }
    return 0;
}
