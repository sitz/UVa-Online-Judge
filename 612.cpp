#include <iostream>
#include <algorithm>

using namespace std;

struct DNA{
       string str;
       int ran;
};

bool comp(DNA A, DNA B){
     return (A.ran < B.ran);
}

int main(){
    int test;
    cin>>test;
    while(test--){
                  int M, N, i, j, k;
                  cin>>N>>M;
                  DNA dna[M];
                  for(i=0; i<M; i++){
                           cin>>dna[i].str;
                           int r=0;
                           for(j=0; j<N-1; j++){
                                    for(k=j+1; k<N; k++){
                                               if(dna[i].str[j] > dna[i].str[k]){
                                                         r++;
                                               }
                                    }
                           }
                           dna[i].ran = r;
                  }
                  stable_sort(dna, dna+M, comp);
                  for(i=0; i<M; i++)
                           cout<<dna[i].str<<endl;
                  if(test > 0)
                          cout<<endl;
    }
    return 0;
}
