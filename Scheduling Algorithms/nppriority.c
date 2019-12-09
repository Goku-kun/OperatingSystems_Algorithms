#include<stdio.h>
#define SIZE 10
int bt[SIZE]={0};

void CompletionTime(int n, int arr[][n]) {

	int row = n;
	int i,j,k=1,x,temp;
	for(i=0;i<row;i++){
		for(j=i+1;j<row;j++){

      if(arr[k][i] > arr[k][j]){

      	for(x=0;x<7;x++){
          temp=arr[x][i];
            arr[x][i]=arr[x][j];
              arr[x][j]=temp;
        }
      }
    }
  }
	for(i=0;i<n;i++){
		bt[i]=arr[2][i];
	}
	int complete = 0, t = 0, largest_pri =0,shortest_ranval = 0, check = 0;
  t=arr[1][0];
	while (complete != n) {
		for (int j = 0; j < n; j++) {
      if ((arr[1][j] <= t) && (arr[6][j] > shortest_ranval ) && bt[j] > 0) {
                largest_pri = j;
                shortest_ranval=arr[6][j];
                check =1;
      }
  	}
    if (check ==0) {
            t++;
    }

    if(check==1) {
      complete++;
      check = 0;
      bt[largest_pri]=0;
      t=arr[2][largest_pri]+t;
      arr[3][largest_pri] = t;
      largest_pri=0;
      shortest_ranval=0;
    }
	}

}


void TurnAroundTime( int n, int arr[][n]) {
	for (int  i = 0; i < n ; i++)
  	arr[4][i] =  arr[3][i] - arr[1][i];
}

void WaitTime( int n, int arr[][n]) {
	for (int  i = 0; i < n ; i++)
  	arr[5][i] =  arr[4][i] - arr[2][i];
}

void FindavgTime( int n, int arr[][n]) {
	int total_wt = 0, total_tat = 0;

	CompletionTime(n, arr);

	TurnAroundTime(n, arr);

	WaitTime(n, arr);

	printf("\n Processes	Priority    Arrival Time	Burst time	Completion Time		Turn around time	Waiting time\n");
	for (int  i=0; i<n; i++)
    	{
        total_wt = total_wt + arr[5][i];
        total_tat = total_tat + arr[4][i];
        printf("   %d ",arr[0][i]);
        printf("\t\t %d ", arr[6][i] );
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

void main() {
	int arr[7][7] = {{1,2,3,4,5,6,7},{0,0,6,7,10,11,12},{3,2,2,3,4,5,3},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{35,20,35,35,50,49,10}};
	int n=4;
	FindavgTime(n, arr);
}
