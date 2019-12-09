#include<stdio.h>
void SearchStack01(int pnt,int tm);
void SearchStack02(int pnt, int tm);
void AddQue(int pnt);
int  ct[50]={0}, qt, rqi[50]={0}, c=0, st, flg=0, tm=0, noe=0, pnt=0, btm[50]={0}, tt, wt;
int at[6]={1,2,3,4,5,6};
int bt[6]={3,4,2,3,1,2};

void main(){

for(int x=0;x<6;x++)
{
    btm[x]=bt[x];
}

printf("\nEnter time quantum:");
scanf("%d",&qt);

do{
    if(flg==0)
	{
       st=at[0];
       if(btm[0]<=qt)
	   {
          tm=st+btm[0];
          btm[0]=0;
          SearchStack01(pnt,tm );
	   }
       else
	   {
          btm[0]=btm[0]-qt;
          tm=st+qt;
          SearchStack01(pnt,tm );
          AddQue(pnt);
	   }
    }
    else
	{
       pnt=rqi[0]-1;
       st=tm;
       for(int x=0;x<noe && noe!=1;x++)
	   {
          rqi[x]=rqi[x+1];
	   }
       noe--;
       if(btm[pnt]<=qt)
	   {
          tm=st+btm[pnt];
          btm[pnt]=0;
          SearchStack02(pnt, tm);
	   }
       else
	   {
         btm[pnt]=btm[pnt]-qt;
          tm=st+qt;
          SearchStack02(pnt, tm);
          AddQue(pnt);
	   }
    }
    if(btm[pnt]==0){
       ct[pnt]=tm;
    }

   flg++;

}while(noe!=0);
	printf("\n\nProcesses	Arrival Time	Burst time	Completion Time		Turn around time	Waiting time\n");
	int n=6;
	int arr[6][6];
	int total_wt=0, total_tat=0;
	for (int  i=0; i<n; i++)
        {arr[0][i]=i+1;
        arr[1][i]=at[i];
        arr[2][i]=bt[i];
        arr[3][i]=ct[i];
            arr[4][i]=arr[3][i]-arr[1][i];
            arr[5][i]=arr[4][i]-arr[2][i];
        total_wt = total_wt + arr[5][i];
        total_tat = total_tat + arr[4][i];
        printf("   %d ",arr[0][i]);
  	printf("\t\t %d ", arr[1][i] );
        printf("\t\t    %d ", arr[2][i] );
        printf("\t\t    %d ",arr[3][i]);
        printf("\t\t\t   %d ",arr[4][i] );
        printf("\t\t\t  %d \n",arr[5][i] );
    	}

        float avgtat =(float)total_tat/n;
        float avgwt = (float)total_wt/n;
        float tp=(float)6/tm;
        printf("\nAverage Turn around Time : %f ", avgtat );
        printf("\nAverage Waiting Time : %f ", avgwt );
    printf("\nThroughput : %f \n", tp );
}

void SearchStack01(int pnt,int tm)
{
    for(int x=pnt+1;x<6;x++)
	{
       if(at[x]<=tm)
	   {
          rqi[noe]=x+1;
          noe++;
	   }
    }
}

void SearchStack02(int pnt, int tm)
{
    for(int x=pnt+1;x<6;x++)
	{

       int fl=0;
       for(int y=0;y<noe;y++)
	   {
          if(rqi[y]==x+1)
		  {
             fl++;
	      }
       }
       if(at[x]<=tm && fl==0 && btm[x]!=0)
	   {
          rqi[noe]=x+1;
          noe++;
	   }
    }
}

void AddQue(int pnt){
    rqi[noe]=pnt+1;
    noe++;
}
