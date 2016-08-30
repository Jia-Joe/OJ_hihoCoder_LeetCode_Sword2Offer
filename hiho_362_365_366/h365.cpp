#pragma once
#pragma comment(linker, "/STACK:102400000,102400000")
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
#define M 12
#define N 1007

typedef unsigned int uint;
typedef long long LL;

int w[N], h[N], fi[N],K, n, ret = 2000000000;
int wi[N], hi[N], ho[N];
void getl(int &W, int &H, int &ix){
	while (ix <= n&&W + w[ix] < K){
		W += w[ix];
		if (h[ix]>H){ H = h[ix]; }
		ix++;
	}
	if (ix <= n){
		int hcf = (h[ix] * (K - W) + w[ix] - 1) / w[ix];
		W = K;
		if (hcf>H){ H = hcf; }
		ix++;
	}
}

void dec(int ix){
	int wa = 0, ha = 0, k=ix;
	getl(wa, ha, ix);
	if (ix > n){
		fi[k] = ha;
		return;
	}
	else{
		fi[k] = fi[ix] + ha;
	}
}

void acc(int ix){
	int k = ix - 1; //wk = wi[k] == K ? 0 : wi[k];
	int hk = wi[k] == 0 ? 0 : hi[k];
	if (wi[k]+w[ix] < K){
		wi[ix] = wi[k] + w[ix];
		hi[ix] = max(hk, h[ix]);		
	}
	else{
		int hcf = (h[ix] * (K - wi[k]) + w[ix] - 1) / w[ix];
		wi[ix] = 0;
		//if (wi[k] == K) hi[ix] = hcf;
		//else
		hi[ix] = max(hk, hcf);
	}
	if (wi[k] == 0)
		ho[ix] = ho[k] + hi[k];
	else
		ho[ix] = ho[k];
}

//#define DEBUG
int main(){
#ifdef DEBUG
	freopen("t1.txt", "r", stdin);
	//freopen("t11.txt", "w", stdout);
#endif
	cin >> K >> n;
	FOI(n){
		scanf("%d %d", &w[i+1], &h[i+1]);
	}
	for (int i = n; i > 0; i--){
		dec(i);
#ifdef DEBUG
		FOI(n + 1)
			cout << fi[i] << " ";
		cout << endl;
#endif
	}
	//cout << endl;
	for (int i = 1; i <=n; i++){
		acc(i);
#ifdef DEBUG
		FOI(n + 1)
			cout << i+1 << ":" << wi[i] << "-" << hi[i] << "-" << ho[i] << "  ";
		cout << endl;
#endif
	}
	for (int i = 1; i <= n; i++){
		int r = ho[i-1];
		int wa = wi[i - 1], ha = hi[i - 1], k = i + 1;
		if (wa == 0) {
			ha = 0;
			r = ho[i];
		}
		getl(wa, ha, k);
		r = r+ha+fi[k];
#ifdef DEBUG
		cout << r << endl;
#endif
		if (r < ret) ret = r;
	}
	cout << ret << endl;

	return 0;
}