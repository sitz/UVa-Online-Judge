#include<iostream>
using namespace std;

int main(){
    for(;;){
            int t;
            cin>>t;
            if(t==0)
                    break;
            int x0,y0;
            cin>>x0>>y0;
            for(int i=0;i<t;i++){
                    int x,y;
                    cin>>x>>y;
                    int dx=x-x0;
                    int dy=y-y0;
                    if(dx>0 && dy>0)
                            cout<<"NE"<<endl;
                    else if(dx<0 && dy>0)
                            cout<<"NO"<<endl;
                    else if(dx<0 && dy<0)
                            cout<<"SO"<<endl;
                    else if(dx>0 && dy<0)
                            cout<<"SE"<<endl;
                    else
                            cout<<"divisa"<<endl;
            }
    }
    return 0;
}
