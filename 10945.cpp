#include<iostream>
#include<string>
using namespace std;
int main(){
    
    for(;;){
            string str;
            getline(cin,str);
            if(str=="DONE")
                           break;
            for(int i=0;i<str.length();i++){
                    if(str[i]=='.' || str[i]==',' || str[i]=='!' || str[i]=='?' || str[i]==' '){
                                   str.erase(i,1);
                    }
                    if(!isalpha(str[i]))
                                     str.erase(i,1);
                    else
                                     str[i]=toupper(str[i]);
            }
            int len=str.length();
            string s;
            for(int i=len-1;i>=0;i--)
                    s+=str[i];
            int cnt=0;
            
            for(int i=0;i<len;i++){
                    if(str[i]==s[i]){
                                         cnt++;
                    }
            }
            if(cnt==len)
                           cout<<"You won't be eaten!"<<endl;
            else
                           cout<<"Uh oh.."<<endl;
    }
    return 0;
}
