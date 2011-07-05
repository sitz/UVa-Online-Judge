#include<iostream>
#include<string>
using namespace std;

int main(){
    long long n=0,i=0;
    cin>>n;
    for(i=0;i<=n;i++){
            string str="\0";
            
            int cnt=0;
            getline(cin, str, '\n');
            for(int J=0;J<str.length();J++){
                    if(str[J]=='a'||str[J]=='d'||str[J]=='g'||str[J]=='j'||str[J]=='m'||str[J]=='p'||str[J]=='t'||str[J]=='w'||str[J]==' ')
                                                         cnt++;
                    if(str[J]=='b'||str[J]=='e'||str[J]=='h'||str[J]=='k'||str[J]=='n'||str[J]=='q'||str[J]=='u'||str[J]=='x')
                                                         cnt+=2;
                    if(str[J]=='c'||str[J]=='f'||str[J]=='i'||str[J]=='l'||str[J]=='o'||str[J]=='r'||str[J]=='v'||str[J]=='y')
                                                         cnt+=3;
                    if(str[J]=='s'||str[J]=='z')
                                    cnt+=4;
            }
            if(i!=0){
                     cout<<"Case #"<<i<<": "<<cnt<<endl;
            }
    }
    return 0;
}
            
