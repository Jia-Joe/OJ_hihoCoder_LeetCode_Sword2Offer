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
#define N 105

typedef unsigned int uint;

int dp[N],dq[N], n;

int main(){

	int p,q,pn=0,qn=0;
	cin >> p >> q;
	for (int i = 1; i <= p; ++i){
		if (p%i == 0){
			dp[pn++] = i;
		}
	}
	for (int i = 1; i <= q; ++i){
		if (q%i == 0){
			dq[qn++] = i;
		}
	}
	FO(i, pn){
		FO(j, qn){
			printf("%d %d\n", dp[i], dq[j]);
		}
	}

	return 0;
}