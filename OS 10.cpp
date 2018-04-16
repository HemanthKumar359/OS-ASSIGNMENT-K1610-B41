#include<stdio.h>
#include<stdlib.h>
#define PREV_REQ 125
#define CURR_REQ 143
int absolute(int num)
{
	return num>0?num:(num*-1);
}
int compare(const void *a,const void *b)
{
	return (*(int *)a-*(int *)b);
}
int main()
{
	int q[]={86,1470,913,1774,948,1509,1022,1750,130};
	int i,s_index,len=sizeof(q)/sizeof(int),dist=0,last,curr;
	qsort(q,len,sizeof(int),compare);
	last=CURR_REQ;
	if(CURR_REQ>=PREV_REQ)
	{
		for(i=0;i<len;i++)
		{
			if(q[i]>CURR_REQ)
			{
				s_index=i;
				break;
			}
		}
		printf("order : %4d\n",last);
		for(i=s_index;i<len;i++)
		{
			printf("%4d\n",q[i]);
			curr=q[i];
			dist+=absolute(last-curr);
			printf("[%d]\n",absolute(last-curr));
			last=curr;
		}
		for(i=s_index;i>0;i--)
		{
			printf("%4d\n",q[i-1]);
			curr=q[i];
			dist+=absolute(last-curr);
			printf("[%d]\n",absolute(last-curr));
			last=curr;
		}
	}
	//elevator going down
	else if(CURR_REQ<PREV_REQ)
	{
		for(i=0;i<len;i++)
		{
			if(q[i]>CURR_REQ)
			{
				s_index=i;
				break;
			}
		}
		printf("order : %4d\n",last);
		for(i=s_index-1;i>=0;i--)
		{
			printf("%4d\n",q[i]);
			curr=q[i];
			dist+=absolute(last-curr);
			printf("[%d]\n",absolute(last-curr));
			last=curr;
		}
		for(i=s_index;i<len;i++)
		{
			printf("%4d\n",q[i]);
			curr=q[i];
			dist+=absolute(last-curr);
			printf("[%d]\n",absolute(last-curr));
			last=curr;
		}
	}
	printf("\n Distance:%d\n",dist);
	return 0*printf("\n Sucessful EXIT\n");
}
