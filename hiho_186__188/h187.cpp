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

vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151 };
LL in, re = 1, nm = 1;
void mdi(int ip, int k, LL mul, LL n){
	int i = 0;
	while (i<=k&&mul*p[ip]<=in){
		mul *= p[ip];
		if (nm < n*(i + 2) || nm == n*(i + 2)&&re>mul){
			nm = n*(i + 2);
			re = mul;
		}
		mdi(ip + 1, i, mul,n*(i+2));
		++i;
		//cout << p[ip]<<":"<<mul<<":"<<nm<<endl;
	}
}
int main(){
	//freopen("t1.txt", "r", stdin);
	//freopen("t11.txt", "w", stdout);
	int t = 200;
	re = 1, nm = 1;
	//in = t;
	cin >> in;
	int k = log2(in) + 1;
	mdi(0, k, 1, 1);
	cout << re << endl;

	return 0;
}