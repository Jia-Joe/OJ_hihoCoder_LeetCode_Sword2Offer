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



int main(){
	freopen("t1.txt", "r", stdin);
	//freopen("t11.txt", "w", stdout);
	int N, K;
	int x[6],xt;
	char c[6],ct;
	bool b[26],s[4];
	FOI(26){
		b[i] = 0;
	}
	cin >> N;
	//int i = 0, j = 0, k = 0;
	while (N--){
		int i = 0, j = 0, k = 0;
		if (scanf("%d<", &x[i])){ ++i; }
		else{ scanf("%c<", &c[j]); j++; }
		if (scanf("%d<", &xt)){
			x[i++] = xt;
			s[k++] = false;
		}
		else{
			scanf("%c<", &ct);
			if (ct == '='){
				s[k++] = false;
			}
			else{
				c[j++] = ct;
			}
		}
		if (scanf("%d", &xt)){
			x[i++] = xt;
			s[k++] = false;
		}
		else{
			scanf("%c", &ct);
			if (ct == '='){
				s[k++] = false;
				scanf("%c", &ct);
				c[j++] = ct;
			}
			else{
				c[j++] = ct;
			}
		}
		scanf("\n");
	}
	cin >> K;
	if (N>13)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;

	return 0;
}