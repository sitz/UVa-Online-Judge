#include<iostream>
using namespace std;

int main(){
    for(;;){
            string str;
            cin>>str;
            if(str=="\0")
                         break;
                    int l=str.length();
                    for(int i=0;i<l/2;i++){
                            if(str[i]==str[l-i-1])
                                                  continue;
                            str.insert(i-i-1,str[i],1);
                            l++;
                    }
                    cout<<str<<endl;
    }
    return 0;
}
