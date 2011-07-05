#include<iostream>
#include<cstdlib>
#include<sstream>
using namespace std;

int main(){
    for(;;){
            string str;
            cin>>str;
            if(str=="END")
                          break;
            char next[100];
            itoa(str.length(),next,10);
            char old[100000]={'\0'};
            for(int j=0;j<str.length();j++)
                    old[j]=str[j];
            int i=1;
            while(sizeof(*old)!=sizeof(*next)){
                                               itoa(sizeof(*next),old,10);
                                               itoa(sizeof(*old),next,10);
                                               i++;
            }
            cout<<i<<endl;
            
    }
    return 0;
}
    
