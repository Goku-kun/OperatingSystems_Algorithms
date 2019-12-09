#include<stdio.h>
#include<stdlib.h>

int main() {
        int pn, pno[50], at[50], bt[50], tat[50], ct[50], wt[50], temp, bttemp[50] = {}, temp1 = 0, temp2;
        float avg, avg2, avgtat;
        printf("Enter the number of processes:\n");
        scanf("%d", & pn);
        printf("Enter the process IDs:\n");
        for (int i = 0; i < pn; i++)
                scanf("%d", & pno[i]);
        printf("Enter the process of Arrival time\n");
        for (int i = 0; i < pn; i++)
                scanf("%d", & at[i]);
        printf("Enter the process burst time\n");
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

        temp2 = 1;
        temp1 = bttemp[0] = bt[0] - 1;

        ct[0] = at[0] + 1;

        for (int i = 1; i < pn; i++) {
                bttemp[i] = bt[i];
        }

        if (bttemp[0] > bttemp[1]) {
                bttemp[pn] = temp2;

                for (int i = 0; i <= pn; i++) {
                        for (int j = i + 1; j <= pn; j++) {
                                if (bttemp[i] > bttemp[j]) {
                                        temp = at[i];
                                        at[i] = at[j];
                                        at[j] = temp;

                                        temp = pno[i];
                                        pno[i] = pno[j];
                                        pno[j] = temp;

                                        temp = bttemp[i];
                                        bttemp[i] = bttemp[j];
                                        bttemp[j] = temp;

                                }
                        }
                }

                pno[0] = bttemp[0];
                at[0] = bttemp[0];

                if (at[1] < at[2]) {
                        ct[1] = ct[0] + bttemp[1];

                        for (int i = 0; i <= pn; i++) {
                                for (int j = i + 1; j <= pn; j++) {
                                        if (at[i] > at[j]) {
                                                temp = at[i];
                                                at[i] = at[j];
                                                at[j] = temp;

                                                temp = pno[i];
                                                pno[i] = pno[j];
                                                pno[j] = temp;

                                                temp = bttemp[i];
                                                bttemp[i] = bttemp[j];
                                                bttemp[j] = temp;

                                        }
                                }
                        }

                        ct[2] = ct[1] + bttemp[1];

                        for (int i = 0; i <= pn; i++) {
                                for (int j = i + 1; j <= pn; j++) {
                                        if (bttemp[i] > bttemp[j]) {
                                                temp = at[i];
                                                at[i] = at[j];
                                                at[j] = temp;

                                                temp = pno[i];
                                                pno[i] = pno[j];
                                                pno[j] = temp;

                                                temp = bttemp[i];
                                                bttemp[i] = bttemp[j];
                                                bttemp[j] = temp;

                                        }
                                }
                        }

                        tat[0] = 0;
                        tat[1] = bttemp[0];

                        wt[0] = 0;
                        for (int i = 3; i <= pn; i++)
                                ct[i] = abs(ct[i - 1] + bttemp[i]); //completion time

                        for (int i = 1; i <= pn; i++)
                                tat[i] = abs(ct[i] - at[i]); //turn aroun time

                        for (int i = 1; i <= pn; i++) {
                                wt[i] = abs(tat[i] - bttemp[i]); //waiting time
                                if (wt[i] == temp1)
                                        wt[i] = wt[i] - 1;

                        }
                } else {
                        for (int i = 0; i <= pn; i++) {
                                for (int j = i + 1; j <= pn; j++) {
                                        if (at[i] > at[j]) {
                                                temp = at[i];
                                                at[i] = at[j];
                                                at[j] = temp;

                                                temp = pno[i];
                                                pno[i] = pno[j];
                                                pno[j] = temp;

                                                temp = bttemp[i];
                                                bttemp[i] = bttemp[j];
                                                bttemp[j] = temp;

                                        }
                                }
                        }

                        ct[1] = ct[0] + bttemp[2];

                        for (int i = 0; i <= pn; i++) {
                                for (int j = i + 1; j <= pn; j++) {
                                        if (bttemp[i] > bttemp[j]) {
                                                temp = at[i];
                                                at[i] = at[j];
                                                at[j] = temp;

                                                temp = pno[i];
                                                pno[i] = pno[j];
                                                pno[j] = temp;

                                                temp = bttemp[i];
                                                bttemp[i] = bttemp[j];
                                                bttemp[j] = temp;

                                        }
                                }
                        }

                        ct[2] = ct[1] + bttemp[1];

                        if (at[1] > at[2]) {
                                temp = at[1];
                                at[1] = at[2];
                                at[2] = temp;

                                temp = pno[1];
                                pno[1] = pno[2];
                                pno[2] = temp;

                                temp = bttemp[1];
                                bttemp[1] = bttemp[2];
                                bttemp[2] = temp;
                        }

                        tat[0] = 0;
                        tat[1] = bttemp[0];

                        wt[0] = 0;
                        for (int i = 3; i <= pn; i++)
                                ct[i] = abs(ct[i - 1] + bttemp[i]);

                        for (int i = 1; i <= pn; i++)
                                tat[i] = abs(ct[i] - at[i]);

                        for (int i = 1; i <= pn; i++) {
                                if (temp1 == bttemp[i])
                                        bttemp[i] += 1;
                                wt[i] = abs(tat[i] - bttemp[i]);
                                if (wt[i] == temp1)
                                        wt[i] = wt[i] - 1;

                        }

                }

                for (int i = 0; i <= pn; i++)
                        avg = avg + tat[i];

                avgtat = avg / pn;

		printf("\nThe computed answer is as follows:\n");
                printf("pno\tat\tbt\tcom\ttat\twt\t\n");
                for (int i = 0; i <= pn; i++) {
                        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pno[i], at[i], bttemp[i], ct[i], tat[i], wt[i]);
                }

                printf("Average TAT is equal to %f\n", avgtat);
        } else {

                bttemp[0] = bttemp[0] + temp2;
                ct[0] = bttemp[0];
                tat[0] = bttemp[0];
                wt[0] = 0;

                for (int i = 1; i < pn; i++) {
                        for (int j = i + 1; j < pn; j++) {
                                if (bttemp[i] > bttemp[j]) {
                                        temp = at[i];
                                        at[i] = at[j];
                                        at[j] = temp;

                                        temp = pno[i];
                                        pno[i] = pno[j];
                                        pno[j] = temp;

                                        temp = bttemp[i];
                                        bttemp[i] = bttemp[j];
                                        bttemp[j] = temp;

                                }
                        }
                }

                for (int i = 1; i < pn; i++)
                        ct[i] = abs(ct[i - 1] + bttemp[i]);

                for (int i = 0; i < pn; i++)
                        tat[i] = abs(ct[i] - at[i]);

                for (int i = 0; i < pn; i++)
                        wt[i] = abs(tat[i] - bttemp[i]);

                for (int i = 0; i < pn; i++)
                        avg = avg + tat[i];

                avgtat = avg / pn;
	 printf("\nThe computed answer is as follows:\n");
                printf("pno\tat\tbt\tcom\ttat\twt\t\n");
                for (int i = 0; i < pn; i++) {
                        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pno[i], at[i], bttemp[i], ct[i], tat[i], wt[i]);
                }

                printf("Average TAT is equal to %f\n", avgtat);
        }

}
