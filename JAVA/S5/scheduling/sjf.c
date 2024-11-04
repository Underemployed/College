#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 5, at[10], bt[10], id[10],ct[10],wt[10],tt[10] ,temp, avg_W = 0, avg_T = 0;
    srand(time(0)); // Seed for random number generation
    int completed = 0;
    for (int i = 0; i < n; i++) {
        id[i] = i + 1;
        at[i] = rand() % 10; 
        bt[i] = rand() % 10 + 1;
        printf("Process %d: Arrival Time = %d, Burst Time = %d\n", id[i], at[i], bt[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (at[j + 1] < at[j]) {
                temp = bt[j + 1];
                bt[j + 1] = bt[j];
                bt[j] = temp;

                temp = at[j + 1];
                at[j + 1] = at[j];
                at[j] = temp;

                temp = id[j + 1];
                id[j + 1] = id[j];
                id[j] = temp;
            }
        }
    }

    printf("\nAfter sorting by at time:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: Arrival Time = %d, Burst Time = %d\n", id[i], at[i], bt[i]);
    }
    int current = 0;
    int total_wt = 0;
    int total_tt = 0;
    for(int i = 0; completed < n; i++) {

        if(current <at[i]){
            current = at[i];
        }
        ct[i] = current + bt[i];
        current = ct[i];

        tt[i] = ct[i] - at[i];
        wt[i] =tt[i] -bt[i];

        total_wt += wt[i];
        total_tt += tt[i];

    }


       printf("\nProcess ID | Arrival Time | Burst Time | Completion Time | Waiting Time | Turnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("%10d %12d %11d %15d %13d %15d\n", id[i], at[i], bt[i], ct[i], wt[i], tt[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tt / n);
    return 0;
}