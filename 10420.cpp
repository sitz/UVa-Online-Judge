#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n=0,i=0;
    cin>>n;
    string allCon[n+1];
    for(i=0;i<n;i++){
                  string name;
                  cin>>allCon[i];
                  getline(cin,name);
    }
    sort(allCon,allCon+n);
    int count=1;
    for(i=0;i<n;i++){
              if(allCon[i]!=allCon[i+1]){
                                        cout<<allCon[i]<<" "<<count<<endl;
                                        count=1;
                                        continue;
              }
              count++;
    }
    return 0;
}
