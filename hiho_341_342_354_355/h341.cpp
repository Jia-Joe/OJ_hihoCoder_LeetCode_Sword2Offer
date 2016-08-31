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
//#define M 12
//#define N 105

typedef unsigned int uint;
typedef long long LL;

struct Rule{
	int x, y;
	char a, b;
	bool e1;
	Rule(){
		x = -1; y = -1;
		a = 0; b = 0;
		e1 = false;
	}
};
Rule ru[1009];
vector<bool> ab(26, 0);

bool ok(map<int, int> &mp, Rule ru){
	if (ru.a) ru.x = mp[ru.a];
	if (ru.b) ru.y = mp[ru.b];
	if (ru.e1)
		return ru.x <= ru.y;
	return ru.x < ru.y;
}
int main(){
	//freopen("t1.txt", "r", stdin);
	//freopen("t11.txt", "w", stdout);
	int N, K = 0, T, rn = 0;
	char ct;
	cin >> N;
	for (int i = 0; i<N; ++i){
		if (scanf("%d<", &ru[rn].x)){}
		else{
			scanf("%c<", &ru[rn].a);
			if (!ab[ru[rn].a - 'A']) { ab[ru[rn].a - 'A'] = 1; K++; }
		}
		while (1){
			if (scanf("%d", &ru[rn].y)){
			}
			else{
				scanf("%c", &ct);
				if (ct == '='){
					ru[rn].e1 = 1;
					if (scanf("%d", &ru[rn].y)){}
					else{
						scanf("%c", &ru[rn].b);
						if (!ab[ru[rn].b - 'A']) { ab[ru[rn].b - 'A'] = 1; K++; }
					}
				}
				else{
					ru[rn].b = ct;
					if (!ab[ru[rn].b - 'A']) { ab[ru[rn].b - 'A'] = 1; K++; }
				}
			}
			rn++;
			if (scanf("%c", &ct), ct == '\n') break;
			ru[rn].a = ru[rn - 1].b;
			ru[rn].x = ru[rn - 1].y;
		}
	}
	scanf("%d\n", &T);
	while (T--){
		bool ret = 1;
		map<int, int> mp;
		int xt;
		FOI(K){
			scanf("%c %d\n", &ct, &xt);
			mp[ct] = xt;
		}
		FOI(rn){
			if (!ok(mp, ru[i])){
				ret = 0; break;
			}
		}
		if (ret)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}