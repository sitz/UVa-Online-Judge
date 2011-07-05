#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void find_lis(vector<int> &a, vector<int> &b)
{
	vector<int> p(a.size());
	int u, v;
 
	if (a.empty()) return;
 
	b.push_back(0);
 
	for (size_t i = 1; i < a.size(); i++) {
		if (a[b.back()] < a[i]) {
			p[i] = b.back();
			b.push_back(i);
			continue;
		}
 
		for (u = 0, v = b.size()-1; u < v;) {
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1; else v=c;
		}
 
		if (a[i] < a[b[u]]) {
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}	
	}
 
	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}
int main(){
    int test;
    char ch[150];
    scanf("%d", &test);
    cin.getline(ch, 150);
    while(test--){
                  vector<int> seq;
                  vector<int> lis;
                  while(true){
                              cin.getline(ch, 150);
                              if(ch == "" || ch=="EOF")
                                    break;
                               int val = atoi(ch);
                              seq.push_back(val);
                  }
                  find_lis(seq, lis);
                  cout<<"Max hits: "<<lis.size()<<endl;
	              for (size_t i = 0; i < lis.size(); i++)
		              cout<<seq[lis[i]]<<endl;
	              if(test > 0)
	                      cout<<endl;
    }
    system("pause");
    return 0;
}
