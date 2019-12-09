#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int n;
int *fibseq;
int i;

void *runn(void *arg);

int main()
{
	printf("Enter a number for the number of characters in fibonnaci series to be printed:");
	scanf("%d", &n);
	fibseq = (int *) malloc(n * sizeof(int));
	pthread_t *threads = (pthread_t *) malloc(n * sizeof(pthread_t));
	for(i=0; i<n; i++)
	{
		pthread_create(&threads[i], NULL, runn, (void *)&i);
		pthread_join(threads[i], NULL);
	}
	printf("The Fibonacci sequence");
	int k;

	for(k=0; k<n-1; k++)
	{
		printf("\n%d", fibseq[k]);
	}
     return 0;
}

void *runn(void *arg)
{
	int *s=(int *)arg;
	int i= *s;
	if(i==0)
	{
		fibseq[i]=0;
		pthread_exit(0);
	}
	if(i==1)
	{
		fibseq[i]=1;
		pthread_exit(0);
	}
	else{
		fibseq[i]= fibseq[i-1] + fibseq[i-2];
		pthread_exit(0);
	}
}
