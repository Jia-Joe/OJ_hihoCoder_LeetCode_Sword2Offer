#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int fun(string s,int p,int q)
{
	int i,z=0;
	if(p==q){return 1;}
	else if(p>q){return 0;}
	else
	{
		for(int t=q;t>=p;t--)
		{

			for(i=p;i<=t;i++)
			{
				if(s[i]==s[t])
				{
					z=z+1+fun(s,i+1,t-1);
				}

			}
		
		}
	}
	return z;
}



int main()
{

	int T;
	cin>>T;
//	string s0;
	vector<string> s(T);
	vector<int> k(T),r(T);
	for(int i=0;i<T;i++)
	{
		cin>>s[i];
		k[i]=s[i].length()-1;

	}

	for(int i=0;i<T;i++)
	{
		r[i]=fun(s[i],0,k[i]);
	}
	for(int i=0;i<T;i++)
	{
		cout<<"Case #"<<i+1<<": "<<r[i]<<endl;
	}
	system("pause");
	return 0;
}
	
//	cout<<strlen(s[1].c_str())<<endl;
//	cout<<strlen(s[1].data())<<endl;
	//cout<<s[1].size()<<endl;
	//cout<<s[1][1]<<endl;
	//string::iterator it=s[1].begin();
	//cout<<*++it;
