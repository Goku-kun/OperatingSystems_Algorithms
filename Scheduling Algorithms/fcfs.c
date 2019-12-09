#include<stdio.h>
#include<stdlib.h>

int main() {
        int p_no, pno[50], at[50], bt[50], tat[50], com[50], wt[50], temp, j;
        float avg, avg2, avgtat;
        printf("\n___FCFS Scheduling___\n");
        printf("Enter the number of process\n");
        scanf("%d", & p_no);

        printf("Enter the Process ID for these processes:\n");
        for (int i = 0; i < p_no; i++)
                scanf("%d", & pno[i]);

        printf("Enter arrival time for each process:\n");
        for (int i = 0; i < p_no; i++)
                scanf("%d", & at[i]);

        printf("Enter burst time for each process:\n");
        for (int i = 0; i < p_no; i++)
                scanf("%d", & bt[i]);

        for (int i = 0; i < p_no; i++) {
                for (j = i + 1; j < p_no; j++) {
                        if (at[i] > at[j]) {
                                temp = at[i];
                                at[i] = at[j];
                                at[j] = temp;

                                temp = pno[i];
                                pno[i] = pno[j];
                                pno[j] = temp;

                                temp = bt[i];
                                bt[i] = bt[j];
                                bt[j] = temp;
                        }
                }
        }

        com[0] = bt[0] + at[0];
        tat[0] = bt[0];
        wt[0] = 0;
        for (int i = 1; i < p_no; i++)
                com[i] = abs(com[i - 1] + bt[i]);

        for (int i = 0; i < p_no; i++)
                tat[i] = abs(com[i] - at[i]);

        for (int i = 0; i < p_no; i++)
                wt[i] = abs(tat[i] - bt[i]);

        for (int i = 0; i < p_no; i++)
                avg = avg + tat[i];

        avgtat = avg / p_no;

        printf("pid\tat\tbt\tct\ttat\twt\t\n");
        for (int i = 0; i < p_no; i++) {
                printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pno[i], at[i], bt[i], com[i], tat[i], wt[i]);
        }

        printf("Avg TAT = %f\n", avgtat);

}
