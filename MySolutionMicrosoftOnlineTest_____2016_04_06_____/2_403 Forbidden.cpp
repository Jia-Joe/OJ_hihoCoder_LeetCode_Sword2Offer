#pragma once

#include <vector>
#include <string>
#include <string.h>
#include <list> 
#include <map>
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

using namespace std;

#define FOR(I,K,N) for(int (I)=(K);(I)<(N);(I)++)
#define FO(I,N) for(int (I)=0;(I)<(N);(I)++)
#define FOI(N) for(int i=0;i<(N);i++)
#define M 12
#define N 100005
typedef unsigned int uint;
#define pa pair<uint,bool>
typedef map<uint,int> mip;
typedef map<uint,int>::iterator mp;
char s[30] = "\0";

/*
void readip(int t,int t2){
	while (t--){
		vector<int> v(5);
		int asc = scanf("allow %d.%d.%d.%d/%d", &v[0], &v[1], &v[2], &v[3], &v[4]);
		int dsc = scanf("deny %d.%d.%d.%d/%d", &v[0], &v[1], &v[2], &v[3], &v[4]);
		if (asc == 4){
			v[4] = 32;
			ipv.push_back(v);
		}
		else if (asc == 5) ipv.push_back(v);

		if (dsc == 4){
			v[4] = 32;
			ipv.push_back(v);
		}
		else if (dsc == 5) ipv.push_back(v);		
		scanf("\n");

	}
	while (t2--){
		vector<int> v(4);
		scanf("%d.%d.%d.%d/n", &v[0], &v[1], &v[2], &v[3]);
		ipv.push_back(v);
	}
}
vector<vector<char>> ipc;
void readchar(int t){
	while (t--){
		vector<char> vc;
		char c;
		while (scanf("%c", &c) != EOF&&c != '\n'){
			vc.push_back(c);
		}
		ipc.push_back(vc);
	}		
}

vector<vector<char>> readchar(){
	vector<vector<char>> ipc;
	int sca = 1;
	while (1){
		vector<char> vc;
		char c;		
		while (sca=scanf("%c", &c), sca!= EOF&&c != '\n'){
			vc.push_back(c);
		}
		ipc.push_back(vc);
		if (sca == EOF) break;
	}
	return ipc;
}

int main(){
	freopen("t1.txt", "r", stdin);
	//freopen("t11.txt", "w", stdout);

	vector<vector<char>> ic=readchar();
	for (vector<char> vc : ic){
		for (char cc : vc){
			cout << cc;
		}
		cout << endl;
	}
	return 0;
}

*/


char readip(uint &ip)
{
	ip = 0;
	char p = '0';
	scanf("%c", &p);
	FOI(4)
	{
		int x;
		for (; p<'0' || p>'9'; scanf("%c", &p));
		for (x = 0; p >= '0'&&p <= '9';)
		{
			x = x * 10 + p - 48;
			if (scanf("%c", &p) == EOF)
				break;
		};
		ip = (ip << 8) + x;
	}
	return p;

};
bool readline(uint &ip,int &mask)
{
	bool allow = true;
	char p;
	scanf("%c", &p);
	if (p == 'a')
		scanf("llow ");
	else if (p == 'd')
	{
		scanf("eny ");
		allow = false;
	}
		
	p=readip(ip);
	if (p == '/')
	{
		int x = 0;
		char px = '0';
		for (; px<'0' || px>'9'; scanf("%c", &px));
		for (x = 0; px >= '0'&&px <= '9';)
		{
			x = x * 10 + px - 48;
			//scanf("%c", &px) == EOF;
			if (scanf("%c", &px) == EOF)
				break;
		}

		mask = x;
	}
	else
		mask = 32;
	return allow;
}

int m, n, r[N];
mip ip[33];
bool out[N], ad[N];//allow deny
uint mk[33], re[100005];
int main(void)
{
	//freopen("q2.txt", "r", stdin);
	memset(out, true, sizeof(bool)* 100005);
	for (int i = 1; i < 33; i++)
	{
		mk[i] = (uint)0xFFFFFFFF - (uint)(1 << (32 - i)) + 1;

	}
	mk[0] = 0;
	scanf("%d %d\n", &m, &n);

	uint ipx,ipy;  int mask;
	FOI(m)
	{
		ad[i] = readline(ipx, mask);
		ipx &= mk[mask];
		if (ip[mask].count(ipx) == 0)
			ip[mask].insert(make_pair(ipx, i));

	}

	FOI(n)
	{
		readip(ipy);
		uint ipt;
		int haha = N;
		bool bt = true;
		for (int k = 0; k < 33; k++)
		{
			ipt = ipy&mk[k];
			mp it = ip[k].find(ipt);
			if (it != ip[k].end())
			{
				if (it->second < haha)
				{
					haha = it->second;
					bt = ad[it->second];
				}
					
			}
		}
		if (bt)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}

//	fclose(stdin);
	system("pause");
	return 0;

}
