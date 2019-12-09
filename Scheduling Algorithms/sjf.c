#include<stdio.h>
#include<stdlib.h>

int main() {
        int pn, pno[50], at[50], bt[50], tat[50], ct[50], wt[50], temp;
        float avg, avg2, avgtat, avgwt;
        printf("\n___SJF algorithm___\n");
        printf("Enter number of processes:\n");
        scanf("%d", & pn);
        printf("Enter process IDs:\n");
        for (int i = 0; i < pn; i++)
                scanf("%d", & pno[i]);
        printf("Enter arrival time for each process:\n");
        for (int i = 0; i < pn; i++)
                scanf("%d", & at[i]);
        printf("Enter burst time for each process:\n");
        for (int i = 0; i < pn; i++)
                scanf("%d", & bt[i]);

        for (int i = 0; i < pn; i++) {
                for (int j = i + 1; j < pn; j++) {
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

        ct[0] = bt[0] + at[0];

        if (ct[0] > at[pn - 1]) {
                for (int i = 1; i < pn; i++) {
                        for (int j = i + 1; j < pn; j++) {
                                if (bt[i] > bt[j]) {
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
                tat[0] = bt[0];
                wt[0] = 0;

                for (int i = 1; i < pn; i++)
                        ct[i] = abs(ct[i - 1] + bt[i]); //completion time
        } else {
                for (int i = 1; i < pn; i++) {
                        for (int j = i + 1; j < pn; j++) {
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

                ct[1] = bt[1] + at[1];

                for (int i = 2; i < pn; i++) {
                        for (int j = i + 1; j < pn; j++) {
                                if (bt[i] > bt[j]) {
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

                tat[0] = bt[0];
                wt[0] = 0;

                for (int i = 2; i < pn; i++)
                        ct[i] = abs(ct[i - 1] + bt[i]);
        }

        for (int i = 0; i < pn; i++)
                tat[i] = abs(ct[i] - at[i]);

        for (int i = 0; i < pn; i++)
                wt[i] = abs(tat[i] - bt[i]);

        for (int i = 0; i < pn; i++)
                avg = avg + tat[i];

        avgtat = avg / pn;

        printf("pno\tat\tbt\tcom\ttat\twt\t\n");
        for (int i = 0; i < pn; i++) {
                printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pno[i], at[i], bt[i], ct[i], tat[i], wt[i]);
        }

        printf("Average TAT is equal to %f\n", avgtat);

}
