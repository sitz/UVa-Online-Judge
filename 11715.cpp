#include<iostream>
#include<cmath>

using namespace std;

int main(){
    long long i=0;
    for(i=1;;i++){
                  int n=0;
                  double u=0,v=0,t=0,a=0,s=0;
                  cin>>n;
                  if(n==0)
                          break;
                          
                  switch(n){
                            
                            case 1:{
                                    cin>>u>>v>>t;
                                    a=(v-u)/t;
                                    s=(u*t)+(a*t*t)/2;
                                    cout<<"Case "<<i<<": ";
                                    printf("%.3f",s);
                                    cout<<" ";
                                    printf("%.3f\n",a);
                                    break;
                                    }
                            case 2:{
                                    cin>>u>>v>>a;
                                    s=(v*v-u*u)/(2*a);
                                    t=(v-u)/a;
                                    cout<<"Case "<<i<<": ";
                                    printf("%.3f",s);
                                    cout<<" ";
                                    printf("%.3f\n",t);
                                    break;
                                    }
                            case 3:{
                                    cin>>u>>a>>s;
                                    v=sqrt(u*u+2*a*s);
                                    t=(v-u)/a;
                                    cout<<"Case "<<i<<": ";
                                    printf("%.3f",v);
                                    cout<<" ";
                                    printf("%.3f\n",t);
                                    break;
                                    }
                            case 4:{
                                    cin>>v>>a>>s;
                                    u=sqrt(v*v-2*a*s);
                                    t=(v-u)/a;
                                    cout<<"Case "<<i<<": ";
                                    printf("%.3f",u);
                                    cout<<" ";
                                    printf("%.3f\n",t);
                                    break;
                                    }
                  }
    }
    return 0;
}
