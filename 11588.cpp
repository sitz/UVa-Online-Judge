#include<iostream>
using namespace std;

int main(){
    int X;
    cin>>X;
    for(int i=1;i<=X;i++){
            int R,C,M,N;
            char img[500]={'\0'};
            int freq[26]={0};
            cin>>R>>C>>M>>N;
            int T=R*C;
            for(int j=0;j<T;j++)
                    cin>>img[j];
            for(int j=0;j<T;j++){
                    char r=img[j];
                    switch(r){
                              case 'A':freq[0]++;
                                                 break;
                              case 'B':freq[1]++;
                                                 break;
                              case 'C':freq[2]++;
                                                 break;
                              case 'D':freq[3]++;
                                                 break;
                              case 'E':freq[4]++;
                                                 break;
                              case 'F':freq[5]++;
                                                 break;
                              case 'G':freq[6]++;
                                                 break;
                              case 'H':freq[7]++;
                                                 break;
                              case 'I':freq[8]++;
                                                 break;
                              case 'J':freq[9]++;
                                                 break;
                              case 'K':freq[10]++;
                                                 break;
                              case 'L':freq[11]++;
                                                 break;
                              case 'M':freq[12]++;
                                                 break;
                              case 'N':freq[13]++;
                                                 break;
                              case 'O':freq[14]++;
                                                 break;
                              case 'P':freq[15]++;
                                                 break;
                              case 'Q':freq[16]++;
                                                 break;
                              case 'R':freq[17]++;
                                                 break;
                              case 'S':freq[18]++;
                                                 break;
                              case 'T':freq[19]++;
                                                 break;
                              case 'U':freq[20]++;
                                                 break;
                              case 'V':freq[21]++;
                                                 break;
                              case 'W':freq[22]++;
                                                 break;
                              case 'X':freq[23]++;
                                                 break;
                              case 'Y':freq[24]++;
                                                 break;
                              case 'Z':freq[25]++;
                                                 break;
                    }
            }
            int max=0;
            for(int j=0;j<26;j++){
                    if(freq[j]>max)
                                   max=freq[j];
            }
            int bytes=0;
            for(int j=0;j<26;j++){
                    if(freq[j]==max)
                                     bytes+=(freq[j]*M);
                    else
                                     bytes+=(freq[j]*N);
            }
            cout<<"Case "<<i<<": "<<bytes<<endl;
    }
    return 0;
}
