#include<stdio.h>

void CompletionTime( int n, int arr[][n]){

	int row = n;
	int i,j,k=1,x,temp;
	for(i=0;i<row;i++)
        {
                for(j=i+1;j<row;j++)
                {
                        if(arr[k][i] > arr[k][j])
                        {
                        	for(x=0;x<6;x++){
                                temp=arr[x][i];
                                arr[x][i]=arr[x][j];
                                arr[x][j]=temp;
                                }
                                }
                        }
                }

	for (int  i = 1; i < n ; i++ )  {
        arr[3][i] =  arr[2][i] + arr[3][i-1] ;
}
}

void TurnAroundTime( int n, int arr[][n]){
	for (int  i = 0; i < n ; i++)
        arr[4][i] =  arr[3][i] - arr[1][i];
}

void WaitTime( int n, int arr[][n]){
	for (int  i = 0; i < n ; i++)
        arr[5][i] =  arr[4][i] - arr[2][i];
}


void FindavgTime( int n, int arr[][n])  {
	int total_wt = 0, total_tat = 0;

	CompletionTime(n, arr);

	TurnAroundTime(n, arr);

	WaitTime(n, arr);

	printf("\n Processes	Arrival Time	Burst time	Completion Time		Turn around time	Waiting time\n");
	for (int  i=0; i<n; i++)
    	{
        total_wt = total_wt + arr[5][i];
        total_tat = total_tat + arr[4][i];
        printf("   %d ",arr[0][i]);
  	printf("\t\t %d ", arr[1][i] );
        printf("\t\t    %d ", arr[2][i] );
        printf("\t\t    %d ",arr[3][i]);
        printf("\t\t\t   %d ",arr[4][i] );
        printf("\t\t\t   %d \n",arr[5][i] );
    	}

	float avgtat =(float)total_tat/n;
	float avgwt = (float)total_wt/n;
	float tp = (float) n/arr[3][n];
	printf("\nAverage Turn around Time : %f ", avgtat );
	printf("\nAverage Waiting Time : %f \n", avgwt );
	printf("\nThroughput : %f jobs/sec \n", tp );

}


void main(){
int arr[6][5] = {{ 1,2,3,4,5},{0,4,3,1,2},{4,5,2,3,1},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
//int arr[6][5] = {{ 1,2,3,4,5},{0,1,1,3,4},{4,3,1,2,5},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
int n=5;
FindavgTime(n, arr);
}
