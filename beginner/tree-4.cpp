#include "stdio.h"
#include "math.h"
#include "iostream"
using namespace std;
#define N 3
int static cnt;

typedef struct Tree 
{
	double data;
	Tree *ap;
	Tree *bp;
	Tree *cp;
	Tree *dp;
}Tree;

Tree *CreateTree(Tree *s,int n)
{

	if(n==1)
	{
		s=new Tree;
		s->ap=NULL;s->bp=NULL;
		s->cp=NULL;s->dp=NULL;
		s->data=cnt++;
//		cnt++;
	
	}
	else
	{
		s=new Tree;
		int x=n;

		s->data=cnt++;
//		cnt++;	

		s->ap=CreateTree(s->ap,x-1);
		s->bp=CreateTree(s->bp,x-1);
		s->cp=CreateTree(s->cp,x-1);
		s->dp=CreateTree(s->dp,x-1);
	
	}
	return s;
	
}
void DeleteTree(Tree *s)
{
	Tree *pr;
	if(s!=NULL)
	{
		cout<<s->data<<endl;
		pr=s->ap;DeleteTree(pr);
		pr=s->bp;DeleteTree(pr);
		pr=s->cp;DeleteTree(pr);
		pr=s->dp;DeleteTree(pr);



	}
}

//void Delete_Tree(Tree *s)
//{
//	Tree *pr;
//	if(s!=NULL)
//	{
//		pr=s->ap;DeleteTree(pr);
//		pr=s->bp;DeleteTree(pr);
//		pr=s->cp;DeleteTree(pr);
//		pr=s->dp;DeleteTree(pr);
//
//	}
//}


void main()
{	
//	Tree tree={0,NULL,NULL,NULL,NULL};
	Tree tree;
	Tree *tr=&tree;
	Tree *tr1=CreateTree(tr,3);


		//s->data=cnt;
		//cnt++;

		//s->ap=CreateTree(s->ap,x-1);
		//s->bp=CreateTree(s->bp,x-1);
		//s->cp=CreateTree(s->cp,x-1);
		//s->dp=CreateTree(s->dp,x-1);
///////////////////////////////////////////////////////////
//                         0                             //
//     1           6             11            16        //
//  2 3 4 5     7 8 9 10    12 13 14 15    17 18 19 20   //
///////////////////////////////////////////////////////////
	cout<<tr1->ap->data<<" "<<tr1->bp->data<<" "<<tr1->cp->data<<" "<<tr1->dp->data<<endl;





	DeleteTree(tr1);
	system("pause");

}