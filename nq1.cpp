#include "stdio.h"
#include "math.h"
#include "iostream"
using namespace std;
#define N 6
int count = 0;
int x[N] = {0};
int place(int k)
{
  int j;
  
  for (j = 0; j < k; j++)
  {
    if ((abs(k - j) == abs(x[j] - x[k])) || (x[j] == x[k]))
      return 0;
  }
  return 1;
}
void queen(int t)
{
  int i,j,k;
  if (t >= N)
  {  
	  count++;
	  		for(k=0;k<N;k++)
		{
			for(j=0;j<N;j++)
			{
				if(j==x[k])
				{cout<<"¡ö";}
				else
				{cout<<"¡õ";}
			}
			cout<<endl;
		}
		cout<<endl<<endl;
  }
  else
  {
    for (i = 0; i < N; i++)
    {  
      x[t] = i;
      if (place(t))
        queen(t + 1);
    }
  }
}
int main()
{
	int a;
 // clrscr();
  queen(0);
  std::cout<<count;
	std::cin>>a;
  return 0;
}
