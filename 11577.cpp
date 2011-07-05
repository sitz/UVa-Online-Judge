#include<iostream>
using namespace std;

int main(){
    char alph[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int t;
    cin>>t;
    for(int i=0;i<=t;i++){
            char ch[250]={'\0'};
            cin.getline(ch,200);
            int freq[26]={0};
            int len=sizeof(ch);
            for(int j=0;j<len;j++){
                    if(isalpha(ch[j]))
                                      ch[j]=tolower(ch[j]);
                    char r=ch[j];
                    switch(r){
                              case 'a':freq[0]++;
                                                 break;
                              case 'b':freq[1]++;
                                                 break;
                              case 'c':freq[2]++;
                                                 break;
                              case 'd':freq[3]++;
                                                 break;
                              case 'e':freq[4]++;
                                                 break;
                              case 'f':freq[5]++;
                                                 break;
                              case 'g':freq[6]++;
                                                 break;
                              case 'h':freq[7]++;
                                                 break;
                              case 'i':freq[8]++;
                                                 break;
                              case 'j':freq[9]++;
                                                 break;
                              case 'k':freq[10]++;
                                                 break;
                              case 'l':freq[11]++;
                                                 break;
                              case 'm':freq[12]++;
                                                 break;
                              case 'n':freq[13]++;
                                                 break;
                              case 'o':freq[14]++;
                                                 break;
                              case 'p':freq[15]++;
                                                 break;
                              case 'q':freq[16]++;
                                                 break;
                              case 'r':freq[17]++;
                                                 break;
                              case 's':freq[18]++;
                                                 break;
                              case 't':freq[19]++;
                                                 break;
                              case 'u':freq[20]++;
                                                 break;
                              case 'v':freq[21]++;
                                                 break;
                              case 'w':freq[22]++;
                                                 break;
                              case 'x':freq[23]++;
                                                 break;
                              case 'y':freq[24]++;
                                                 break;
                              case 'z':freq[25]++;
                                                 break;
                    }
            }
            int max=0;
            for(int j=0;j<26;j++){
                    if(freq[j]>max)
                                   max=freq[j];
            }
            if(i!=0){
            for(int j=0;j<26;j++){
                    if(freq[j]==max)
                                    cout<<alph[j];
            }
            cout<<endl;
            }
    }
    return 0;
}
