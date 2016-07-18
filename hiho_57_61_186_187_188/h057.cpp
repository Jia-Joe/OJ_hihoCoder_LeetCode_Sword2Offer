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
#define M 12
#define N 20008

typedef unsigned int uint;

struct timesp{
	int h, m, se;
};

bool legal(timesp a, timesp b){
	if (a.h != b.h) return a.h<b.h;
	if (a.m != b.m) return a.m<b.m;
	return a.se <= b.se;
}
timesp dif(timesp b, timesp a){
	int sa = a.h * 3600 + a.m * 60 + a.se;
	int sb = b.h * 3600 + b.m * 60 + b.se;
	int sc = sb - sa;
	timesp r;
	r.h = sc / 3600; r.m = sc % 3600 / 60; r.se = sc % 3600 % 60;
	return r;
}
timesp ts[N], df[N / 2];
bool bg[N];
char s[N][260], r[N / 2][260];

int main(){
	//freopen("t1.txt", "r", stdin);
	//freopen("t11.txt", "w", stdout);
	int T;
	scanf("%d\n", &T);
	FOI(T){
		scanf("%s %d:%d:%d ", s[i], &ts[i].h, &ts[i].m, &ts[i].se);
		char c;
		if (scanf("STAR%c", &c)==1) bg[i] = 1;
		if (scanf("EN%c", &c)==1) bg[i] = 0;
		scanf("\n");
	}
	if (bg[0] == false){
		cout << "Incorrect performance log" << endl; return 0;
	}
	stack<char*> sk;
	stack<int> ix, kx;
	int k = 0;
	for (int i = 0; i < T; ++i){
		if (i != 0 && !legal(ts[i - 1], ts[i])){
			cout << "Incorrect performance log" << endl; return 0;
		}
		if (bg[i] == true) {
			sk.push(s[i]);
			ix.push(i);
			kx.push(k);
			strcpy(r[k], s[i]);
			++k;
		}
		else {
			if (strcmp(s[i], sk.top())) {
				cout << "Incorrect performance log" << endl; return 0;
			}
			else{
				if (!legal(ts[ix.top()], ts[i])){
					cout << "Incorrect performance log" << endl; return 0;
				}
				df[kx.top()] = dif(ts[i], ts[ix.top()]);
				sk.pop(); ix.pop();	kx.pop();
			}
		}
	}
	if (!sk.empty()){
		cout << "Incorrect performance log" << endl; return 0;
	}
	else{
		FOI(T / 2){
			printf("%s %02d:%02d:%02d\n", r[i], df[i].h, df[i].m, df[i].se);
			//printf("%s\n", r[i]);
		}
	}
	//vector<vector<char>> ic=readchar();
	//for (vector<char> vc : ic){
	//	for (char cc : vc){
	//		cout << cc;
	//	}
	//	cout << endl;
	//}
	return 0;
}