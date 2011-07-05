#include<iostream>
using namespace std;
int main(){
    int test;
    cin>>test;
    cout<<"INTERSECTING LINES OUTPUT\n";
    while(test--){
                  double x1,y1,x2,y2;
                  double x3,y3,x4,y4;
                  double m1,m2,m3,m4;
                  double ptx,pty;
                  cin>>x1>>y1>>x2>>y2;
                  cin>>x3>>y3>>x4>>y4;
                  m1=(y2-y1)/(x2-x1);
                  m2=(y4-y3)/(x4-x3);
                  if(x1==x2 || x3==x4){
                            if(x1==x2){
                                       ptx=x1;
                                       pty=m2*(x1-x3)+y3;
                            }
                            else{
                                 ptx=x3;
                                 pty=m1*(x3-x1)+y1;
                            }
                            printf("POINT %.2lf %.2lf\n",ptx,pty);
                            continue;
                  }
                  else if(y1==y2 || y3==y4){
                            if(y1==y2){
                                       pty=y1;
                                       ptx=(y1-y3)/m2 + x3;
                            }
                            else{
                                       pty=y3;
                                       ptx=(y3-y1)/m1 + x1;
                            }
                            printf("POINT %.2lf %.2lf\n",ptx,pty);
                            continue;
                  }
                  else if(m1==m2){
                              m3=(y3-y1)/(x3-x1);
                              m4=(y4-y2)/(x4-x2);
                              if(m3==m4){
                                        cout<<"LINE"<<endl;
                                        continue;
                              }
                              else{
                                        cout<<"NONE"<<endl;
                                        continue;
                              }
                  }
                  else{
                       ptx=(y3-y1+m1*x1-m2*x3)/(m1-m2);
                       pty=(m1*(y3-m2*x3)-m2*(y1-m1*x1))/(m1-m2);
                       printf("POINT %.2lf %.2lf\n",ptx,pty);
                  }
                  
    }
    cout<<"END OF OUTPUT\n";
    return 0;
}
