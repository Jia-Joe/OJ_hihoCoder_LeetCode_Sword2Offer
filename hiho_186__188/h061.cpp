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
#define N 10000000000000000

typedef unsigned int uint;
typedef long long LL;


int T;
int main(){
	//freopen("t1.txt", "r", stdin);
	//freopen("t11.txt", "w", stdout);
	scanf("%d\n", &T);
	while (T--){
		LL n;
		scanf("%lld\n", &n);

		bool ok=0;
		LL pn=1,qn=0,rn=0;
		vector<char> v(n);
		for (LL w = 0; w < n; ++w){
			scanf("%c", &v[w]);
		}
		scanf("\n");
		LL i = 1;
		while (i < n&&v[i] == v[i - 1]){
			++i; ++pn;
		}
		//aabbbccdde
		while(i<n){
			if (v[i] != v[i - 1] + 1 && v[i] != v[i - 1]){
				++i;
				pn = 1; qn = 0, rn = 0;
				continue;
			} 
			if (qn == 0){
				if (v[i] == v[i - 1]){
					while (i < n&&v[i] == v[i - 1]){
						++i; ++pn;
					}
					continue;
				}
				
				++i; qn++;
				while (i < n&&v[i] == v[i - 1]){
					++i; ++qn;
				}
				if (qn>pn){
					pn = qn;
					qn = 0; rn = 0;
					continue;
				}
				else{
					if (i >= n) break;
					else if (i < n&&v[i] != v[i - 1] + 1){
						pn = 1; qn = 0; rn = 0;  continue;
					}
					else{
						++i; rn++;
						while (i < n&&v[i] == v[i - 1]){
							++i; ++rn;
						}
						if (rn >= qn){
							ok = 1;
							break;
						}
						else{
							pn = qn; qn = rn; rn = 0;
						}
					}
				}
				
			}
			else{
				if (v[i] == v[i - 1]){
					while (i < n&&v[i] == v[i - 1]){
						++i; ++pn;
					}
					continue;
				}
				++i; rn++;
				while (i < n&&v[i] == v[i - 1]){
					++i; ++rn;
				}
				if (rn >= qn){
					ok = 1;
					break;
				}
				else{
					pn = qn; qn = rn; rn=0;
				}				
			}
			
			
		}
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}


	return 0;
}