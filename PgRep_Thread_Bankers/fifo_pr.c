#include<stdio.h>
int in(int size, int* array, int value){
	int i;
	for(i=0;i<size;i++){
		if(array[i] == value)
			return 1;
	}
	return 0;
}
int main(){
	int n;
	printf("Enter number of page requests: ");
	scanf("%d", &n);
	int m;
	printf("Enter number of pages: ");
	scanf("%d", &m);
	int currPages[m];
	int pageRequests[n];
	printf("Enter the page requests separated by space: \n");
	int i;
	for(i=0;i<n;i++) scanf("%d", &pageRequests[i]);
	int faults=0;
	int index=-1;
    for(i=0;i<m;i++) currPages[i] = -1;
	for(i=0;i<n;i++){
		if(in(m, currPages, pageRequests[i])) continue;
		else{
			currPages[(++index)%m] = pageRequests[i];
			faults++;
		}
	}
		printf("FIFO:\n");
    printf("\tPage faults : %d\n", faults);
    printf("\t       Hits : %d\n", n - faults);
    printf("\t  Hit Ratio : %.2f%%\n", (n-faults)*100.0/n);
}
