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
typedef long long LL;

int dp[N],dq[N], n, ret=0;
map<string> st;
int main(){
	freopen("t1.txt", "r", stdin);
	//freopen("t11.txt", "w", stdout);
	cin >> n;
	FOI(n){
		string s;
		cin >> s;
		string sr = string(s.rbegin(), s.rend());
		
		if (st.find(sr) != st.end()){
			ret++;
		}
		else{
			st.insert(s);
		}
		//reverse(s.begin(), s.end());
		//cout << s<<endl;
	}

	cout << ret << endl;
	return 0;
}