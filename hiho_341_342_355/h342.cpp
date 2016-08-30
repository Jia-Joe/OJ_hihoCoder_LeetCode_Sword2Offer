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

int xa[20], ya[20];
void getx(int n, vector<vector<int>> &v, vector<vector<int>> &vy){
	vector<int> vb,vby;
	int f = 1;
	for (int i = -xa[n - 1]; i <= xa[n - 1]; ){
		vb.push_back(i);
		if (f){
			i = i + 4;
		}
		else{
			i+=2;
		}
		f = 1 - f;
		if (n == 1)
			vby.push_back(0);
		else
			vby.push_back(ya[n-1]-1);
	}
	v[n - 1] = vb;
	vy[n - 1] = vby;
	for (int i = n - 2; i >= 0; i--){
		vector<int> vt,vty;
		for (int k = 0; k < v[i + 1].size(); k += 2){
			vt.push_back((v[i + 1][k] + v[i + 1][k + 1]) >>1);
			if (i==n-2)
			vty.push_back(vy[i+1][0]+1-ya[n-i-2]);
			else
				vty.push_back(vy[i + 1][0] - ya[n - i - 2]);
		}
		v[i] = vt;
		vy[i] = vty;
	}
	vy[0][0] = 0;

}

int main(){
	//freopen("t1.txt", "r", stdin);
	//freopen("t11.txt", "w", stdout);
	ya[0] = 3; ya[1] = 3;
	for (int i = 2; i < 20; i++){
		ya[i] = ya[i - 1] << 1;
	}
	xa[0] = 0; xa[1] = 2;
	for (int i = 2; i < 20; i++){
		xa[i] = (xa[i - 1] << 1)+1;
	}
	int N, M, x1,y1,x2,y2;
	cin >> N >> M;
	vector<vector<int>> vx(N),vy(N);
	getx(N, vx, vy);
	//for (vector<int> v : vx){
	//	for (int x : v)
	//		cout << x << " ";
	//	cout << endl;
	//}
	//cout << endl;
	//for (vector<int> v : vy){
	//	for (int y : v)
	//		cout << y << " ";
	//	cout << endl;
	//}

	while (M--){
		int re=0;
		scanf("%d %d %d %d\n", &y1, &x1, &y2, &x2);
		for (int i = 0; i < vx.size(); i++){
			for (int j = 0; j < vx[i].size(); j++){
				int x = vx[i][j], y = vy[i][j];
				if (x1 <= x&&x <= x2&&y1 <= y&&y <= y2){
					re++;
				}
			}
		}

		cout << re << endl;
	}
	return 0;
}