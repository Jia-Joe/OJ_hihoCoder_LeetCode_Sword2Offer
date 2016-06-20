package Algorithm;

import java.util.Stack;
import java.util.Calendar;

public class QuicksortRuntimeCmp {

	public static void main(String[] args) {
		int N=6000,K=100;
		int s[]=gen(N);
		long start[]=new long[K];
		long end[]=new long[K];
		
/**		Three ways to compare:
		qsRecursion(s1,0,N-1);
		qsStackLib(s2,0,N-1);		
		qsMyStack(s,N,0,N-1);
*/		
///////////////////////////////////////////////////////
//		avg runtime with fixed input:my<lib<re       //
//		variance with fixed input:re<lib<my          //
//		avg runtime with random ibout:re<<my<lib     //
///////////////////////////////////////////////////////		
		
		for (int i=0;i<K;i++) {
//			int[] s1=gen(N);
			int[] s1=s;
			start[i]=Calendar.getInstance().getTimeInMillis();
			qsRecursion(s1,0,N-1);
//			qsStackLib(s1,0,N-1);
//			qsMyStack(s1,0,N-1);
			end[i]=Calendar.getInstance().getTimeInMillis();
			System.out.println(end[i]-start[i]);
		}
		
//		long start0=Calendar.getInstance().getTimeInMillis();
//		qsRecursion(s1,0,N-1);
//		long end0=Calendar.getInstance().getTimeInMillis();
//		
//		long start2=Calendar.getInstance().getTimeInMillis();
//		qsStackLib(s2,0,N-1);
//		long end2=Calendar.getInstance().getTimeInMillis();
//
//		long start3=Calendar.getInstance().getTimeInMillis();
//		qsMyStack(s3,0,N-1);
//		long end3=Calendar.getInstance().getTimeInMillis();
//		
//		long start1=Calendar.getInstance().getTimeInMillis();
//		qsStackLib(s,0,N-1);
//		long end1=Calendar.getInstance().getTimeInMillis();


		
//		System.out.println(Arrays.toString(s));		
//		System.out.println(Arrays.toString(s1));
//		System.out.println(Arrays.toString(s2));
//		System.out.println(Arrays.toString(s3));	
//		System.out.println(end0-start0);
//		System.out.println(end1-start1);
//		System.out.println(end2-start2);
//		System.out.println(end3-start3);
	}
	public static void qsRecursion (int[] s,int p,int q) {
		if(p<q) {
			int a=s[p],x=p;
			for(int i=p+1;i<=q;i++) {
				if(s[i]<a) {
					x++;
//					swap(s,x,i);
					int temp=s[x];s[x]=s[i];s[i]=temp;
				}
			}
//			swap(s,x,p);
			int temp=s[x];s[x]=s[p];s[p]=temp;
			qsRecursion(s,p,x-1);
			qsRecursion(s,x+1,q);
		}
	}

	
	public static void qsStackLib (int[] s,int p,int q) {
		Stack<Integer> stack=new Stack();
		if(p<q) {
			stack.push(p);
			stack.push(q);
		}
		while(!stack.empty()) {
			int qq=stack.pop();
			int pp=stack.pop();
			int a=s[pp],x=pp;
			for(int i=pp+1;i<=qq;i++) {
				if(s[i]<a) {
					x++;
//					swap(s,x,i);
					int temp=s[x];s[x]=s[i];s[i]=temp;
				}
			}
//			swap(s,x,pp);
			int temp=s[x];s[x]=s[p];s[p]=temp;
			if(pp<x-1) {
				stack.push(pp);
				stack.push(x-1);
			}
			if(x+1<qq) {
				stack.push(x+1);
				stack.push(qq);
			}
		}
		
	}
	public static void qsMyStack (int[] s,int p,int q) {
		int[] stack=new int[28000];
		int sp=0;
		if(p<q) {
			stack[++sp]=p;
			stack[++sp]=q;
		}
		while(sp>0) {
			int qq=stack[sp--];
			int pp=stack[sp--];
			int a=s[pp],x=pp;
			for(int i=pp+1;i<=qq;i++) {
				if(s[i]<a) {
					x++;
//					swap(s,x,i);
					int temp=s[x];s[x]=s[i];s[i]=temp;
				}
			}
//			swap(s,x,pp);
			int temp=s[x];s[x]=s[p];s[p]=temp;
			if(pp<x-1) {
				stack[++sp]=pp;
				stack[++sp]=x-1;
			}
			if(x+1<qq) {
				stack[++sp]=x+1;
				stack[++sp]=qq;
			}
		}		
	}
	public static int[] gen(int n) {
		int s[] = new int[n];
		for(int i=0;i<n;i++) {
			s[i]=(int)(Math.random()*1000000);
		}
		return s;
	}

	public static void swap(int s[],int a,int b) {
		int temp=s[a];
		s[a]=s[b];
		s[b]=temp;
	}
}
