#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;

using namespace std;
struct Robot{
       int X;
       int Y;
       char dir;
};

int main(){
    while(true){
                int I, J, S;
                int i=0, j=0, sticker=0;
                cin>>I>>J>>S;
                if(I==0 && J==0 && S==0)
                        break;
                string mat[I], path;
                for(i=0; i<I; i++)
                         cin>>mat[i];
                cin>>path;
                Robot robo;
                bool stat=true;
                for(i=0; i<I; i++){
                         for(j=0; j<J; j++){
                                  if(mat[i][j]=='N' || mat[i][j]=='S' || mat[i][j]=='L' || mat[i][j]=='O'){
                                                    robo.X=i;
                                                    robo.Y=j;
                                                    robo.dir=mat[i][j];
                                                    stat = false;
                                                    break;
                                  }
                         }
                         if(!stat)
                                  break;
                }
                for(i=0; i<S; i++){
                         if(path[i] == 'F'){
                                    if(robo.dir=='N'){
                                                      if((robo.X == 0) || (mat[robo.X-1][robo.Y]=='#'))
                                                                continue;
                                                      else
                                                          robo.X--;
                                                      if(mat[robo.X][robo.Y]=='*'){
                                                                                   sticker++;
                                                                                   mat[robo.X][robo.Y]='.';
                                                      }
                                                                                   
                                    }
                                    else if(robo.dir=='S'){
                                                      if((robo.X + 1 == I) || (mat[robo.X+1][robo.Y]=='#'))
                                                                continue;
                                                      else
                                                          robo.X++;
                                                      if(mat[robo.X][robo.Y]=='*'){
                                                                                   sticker++;
                                                                                   mat[robo.X][robo.Y]='.';
                                                      }
                                    }
                                    else if(robo.dir=='O'){
                                                      if((robo.Y == 0) || (mat[robo.X][robo.Y-1]=='#'))
                                                                continue;
                                                      else
                                                          robo.Y--;
                                                      if(mat[robo.X][robo.Y]=='*'){
                                                                                   sticker++;
                                                                                   mat[robo.X][robo.Y]='.';
                                                      }
                                    }
                                    else if(robo.dir=='L'){
                                                      if((robo.Y + 1 == J) || (mat[robo.X][robo.Y+1]=='#'))
                                                                continue;
                                                      else
                                                          robo.Y++;
                                                      if(mat[robo.X][robo.Y]=='*'){
                                                                                   sticker++;
                                                                                   mat[robo.X][robo.Y]='.';
                                                      }
                                    }
                         }
                         else if(path[i] == 'D'){
                              if(robo.dir == 'N')
                                          robo.dir = 'L';
                              else if(robo.dir == 'L')
                                          robo.dir = 'S';
                              else if(robo.dir == 'S')
                                          robo.dir = 'O';
                              else if(robo.dir == 'O')
                                          robo.dir = 'N';
                         }
                         else if(path[i] == 'E'){
                              if(robo.dir == 'N')
                                          robo.dir = 'O';
                              else if(robo.dir == 'L')
                                          robo.dir = 'N';
                              else if(robo.dir == 'S')
                                          robo.dir = 'L';
                              else if(robo.dir == 'O')
                                          robo.dir = 'S';
                         }
                }
                cout<<sticker<<endl;
    }
    return 0;
}
