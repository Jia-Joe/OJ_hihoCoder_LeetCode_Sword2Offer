//Binary search is better!

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

int n,m,l;
set<char> st;
inline int tr(int x){
	return (x + n) % n;
}
int main(){
	//freopen("t1.txt", "r", stdin);
	//freopen("t11.txt", "w", stdout);
	//vector<int> v = { 1, 2, 3, 4, 5 };
	cin >> n >> m >> l;
	vector<int> v(n),vc(n),vm(n);
	FOI(n){
		scanf("%d", &v[i]);
		vc[i] = i;
	}
	vector<int> vs=v;
	sort(vs.begin(), vs.end());
	sort(vc.begin(), vc.end(), [&v](int x, int y){ return v[x] < v[y]; });
	int L = vs[m], R = vs[l*m], re=R, ib=vc[0],iw;
	for (iw = l*m; iw >= m; iw--){
		//cout << iw << "==" << endl;
		int r = n;
		for (int j = 1; j <=  l; j++){
			int ix = tr(ib - l + j),k=tr(ix+l),ic=1;
			//cout << v[ix] << endl;
			while (k!=ix){
				if (v[k] < vs[iw]){
					ic++;
					int lc = l;
					while (lc--){
						k = tr(k + 1);
						if (k == ix)
							break;
					}
					
				}
				else
					k = tr(k + 1);
			}
			if (ic < r) r = ic;
		}
		if (r <= m){ break; }
	}
	cout << vs[iw] << endl;
	return 0;
}