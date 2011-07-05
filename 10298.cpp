#include<iostream>
using namespace std;
int main(){
    for(;;){
            long long i=0,min=10000000;
            string str;
            getline(cin,str,'\n');
            if(str==".")
                        break;
            if(str==""){
                       cout<<"0\n";
                       continue;
            }
            int len=str.length();
            int allStr[130]={0},actStr[130]={0};
            for(i=0;i<len;i++){
                               allStr[str[i]-'\0']++;
                               actStr[str[i]-'\0']=1;
            }
            for(i=0;i<130;i++){
                            if(actStr[i]==1)
                                            min=min<=allStr[i]?min:allStr[i];
            }
            cout<<len/min<<endl;
    }
    return 0;
}
