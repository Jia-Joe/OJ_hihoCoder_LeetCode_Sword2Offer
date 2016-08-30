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
#define M 100003
#define N 12
#define eps (1e-12)
#define mkp(A,B) make_pair((A),(B))

typedef unsigned int uint;
typedef long long LL;

int a[N], b[N], n;
double t[M][N];

struct cmp {
	bool operator() (pair<double, int> x, pair<double, int> y){
			return x.first<y.first; 
	}
};
priority_queue<pair<double, int>, vector<pair<double, int>>, cmp> pq;
//bool dd(pair<int, int> &x, pair<int, int> &y){return x.first>y.first;}


int main(){
	std::ios::sync_with_stdio(false);
	freopen("t1.txt", "r", stdin);
	//freopen("t11.txt", "w", stdout);
	int K;
	double P = 0, c[N];
	cin >> n >> K;
	FOI(K){
		cin >> a[i];
	}
	FOI(K){
		cin >> b[i];
	}

	FOI(K){
		pq.push(mkp(log(1/(0.0+a[i])+1)/b[i],i));
	}
	vector<int> v(n, 0);
	FOI(n){
		int t = pq.top().first, ix=pq.top().second;
		v[ix]++;
		pq.pop();
		pq.push(mkp(log(1 / (0.0 + v[ix] + a[ix]) + 1) / b[ix], ix));
	}
	//double sum = 0;
	//FOI(K){
	//	sum = sum + log(a[i] + v[i]) / b[i];
	//}
	//sum=exp(sum);
	double sum = 1;
	FOI(K){
		sum = sum * pow(a[i] + v[i], 1 / (b[i]+0.0));
	}
	//int s = (sum + 0.005) * 100;
	//cout << s/100.0 << endl;
	cout << fixed << setprecision(4) << sum << endl;
	return 0;
}