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
#define M 10005
//#define N 100

typedef unsigned int uint;
typedef long long LL;
//int t[M], l[M], n[M];bool d[M];
//vector<int> t(M), l(M), n(M);
//bool d[M];

int ok(int t, int T, int l, int L){
	bool p, n;
	n = T >= t + l || T <= t - L;
	if (L>l)
		p = T >= t || T <= t + l - L;
	else
		p = T <= t || T >= t + l - L;
	if (p&&n) return 2;
	if (p) return 1;
	if (n) return -1;
	else return 0;
}

struct plan{
	int t, l, n, d;
	plan(int tt, int ll, int nn, int dd) :t(tt), l(ll), n(nn), d(dd){};
	plan(){};

};
bool cmp(const plan &a, const plan &b){
	return a.n < b.n;
}
int main(){
	//freopen("t1.txt", "r", stdin);
	//freopen("t11.txt", "w", stdout);
	int TA;
	cin >> TA;
	while (TA--){
		int T, L, R, N, Q;
		cin >> T >> L >> R >> N >> Q;
		vector<plan> pn(Q);

		int ts = T;
		FOI(Q){
			scanf("%d %d %d %d", &pn[i].t, &pn[i].l, &pn[i].n, &pn[i].d);
			//cin >> t[i] >> l[i] >> n[i] >> d[i];
		}
		//////
		sort(pn.begin(), pn.end(), cmp);

		vector<int>px;
		px.push_back(0);
		int in = 1;
		for (int i = 1; i < Q; ++i){
			if (pn[i].n != pn[i - 1].n)
				px.push_back(i), in++;
		}
		px.push_back(Q);

		bool dir = 0;
		while (R)
		{
			vector<bool> nok(N, 1);
			int k = 1;
			while (k<px.size()){
				bool rd = 1;
				for (int i = px[k - 1]; i < px[k]; ++i){
					int tr = ok(pn[i].t, ts, pn[i].l, L);
					//find nth lane false
					if ((dir == pn[i].d && (tr == -1 || tr == 0)) || (dir != pn[i].d && (tr == 1 || tr == 0))){
						nok[pn[i].n] = false;
						k++;
						rd = 0;
						break;
					}
				}
				if (rd) {
					ts += L;
					R--;
					dir = !dir;
					break;
				}
			}
			if (k >= px.size()){
				ts++;
			}
		}

		//////
		cout << ts << endl;
	}


	return 0;
}


//TLE solution
int main(){
	//freopen("t1.txt", "r", stdin);
	//freopen("t11.txt", "w", stdout);
	int TA;
	cin >> TA;
	while (TA--){
		int T, L, R, N, Q;
		cin >> T >> L >> R >> N >> Q;
		int ts = T;
		FOI(Q){
			cin >> t[i] >> l[i] >> n[i] >> d[i];
		}
		//
		bool dir = 0;
		while (R)
		{
			vector<bool> nok(N, 1);
			for (int i = 0; i < Q; ++i){
				int tr = ok(t[i], ts, l[i], L);
				if (dir == (bool)d[i] && (tr == -1 || tr == 0)){
					nok[n[i]] = false;
				}
				if (dir != (bool)d[i] && (tr == 1 || tr == 0)){
					nok[n[i]] = false;
				}				
			}
			int j=0;
			for (; j < N; ++j){
				if (nok[j]){
					ts += L;
					R--;
					dir = !dir;
					break;
				}
			}
			if (j == N){
				ts++;
			}
		}
		
		//
		cout << ts << endl;
	}

	return 0;
}