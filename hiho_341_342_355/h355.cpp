#pragma once
#include <vector>
#include <string>
#include <string.h>
#include <list> 
#include <map>
#include <set>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iomanip>
#include <utility>
#include <hash_set>
#include <sstream>
#include <functional> 
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define FOR(I,K,N) for(int (I)=(K);(I)<(N);(I)++)
#define FO(I,N) for(int (I)=0;(I)<(N);(I)++)
#define FOI(N) for(int i=0;i<(N);i++)
#define MA 100000000
#define N 205

typedef unsigned int uint;
typedef long long LL;

int n, m, l;
char *p[60];
int wz[60];
unordered_map<int, pair<int, LL>> mp;
int main(){
	freopen("t1.txt", "r", stdin);
	//freopen("t11.txt", "w", stdout);
	cin >> n >> m;
	int iw = 0, w = -1, sz = 0;
	LL h = 1;
	FOI(60){
		p[i] = new char[102];
	}
	while (scanf("%s", p[iw]) != EOF){
		wz[iw] = strlen(p[iw]);
		sz = sz + wz[iw] + 1;
		iw++;
	}
	//sz--;

	int nt = n, fl = -1;
	bool bk = false,gb=true;
	FOI(nt){
		int j = 0;
		unordered_map<int, pair<int, LL>>::iterator it = mp.find(fl);
		if (it == mp.end()){
			mp[fl] = make_pair(i, h);
		}
		else if(gb){
			//if (bk){ h++; }
			int n1 = it->second.first, nd = i - n1, nq = (n - n1) / nd;
			LL h1 = it->second.second;
			if (h1 == 1 && n1 == 0) h1--;
			LL hd = h - h1;
			i = n1 + nq*nd;
			h = h1 + nq*hd;
			//if (h1 == 1 && n1 == 0) h--;
			if (i >= nt) {
				if (fl == -1 && bk) { h--; };
				break;
			}
			//bk = false; 
			gb = false;
		}

		while (j<iw){
			if (w == m) { w = 0; h++; }
			while (j<iw&&w + wz[j] + 1 < m){
				w = w + wz[j] + 1;
				j++;
				//cout << j<<": "<<w << " " << h << endl;
			}
			if (j<iw){
				if (w + wz[j] + 1 == m){
					w = m; j++;
					//cout << j << ": " << w << " " << h << endl;
				}
				else{
					h++;  w = -1;
				}

			}
			if (j == iw){
				if (w + wz[0] + 1 < m) { fl = w; }
				else if (w + wz[0] + 1 == m) { fl = 0;  }
				else {
					if (w == m) fl = 0;
					else fl = -1;
				}
			}
		}

	}

	cout << h << " " << w << endl;
	return 0;
}
/*TEST CASES
50 40 
Good good study day day
32 7

4 2
aa aa
15 2

2 7 
Gooda a
3 1
*/