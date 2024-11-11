#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 10

int random(int min, int max) {
    int r = rand();
    while (r < min || r > max) {
        r = rand();
    }
    return r;
}

void swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}


int fcfs() {
    int at[n], pid[n], bt[n], i;
    for (i = 0; i < n; i++) {
        at[i] = random(0, n);  
        bt[i] = random(1, n);   
        pid[i] = i;
    }

    printf("PID\tAT\tBT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", pid[i], at[i], bt[i]);
    }
    int ct[n], tt[n], wt[n];
    // nithins bubble sort dont mind
    // sorting based on burst time
    int count = 0;
    int swapped = 1;
    while(swapped){
        swapped = 0;
        for (int i = 0; i < n -1-count;i++){
            int j = i + 1;
            // bt and (if bt equal sort on at)
            if(bt[i] > bt[j] || (bt[i] == bt[j] && at[i] > at[j])){
                swap(&at[i], &at[j]);
                swap(&bt[i], &bt[j]);
                swap(&pid[i], &pid[j]);
                swapped = 1;
            }
        }
        count++;
    }
    // sorting end
    //sjf calc
    // first process
    ct[0] = at[0] + bt[0];
    tt[0] = ct[0] - at[0];
    wt[0] =  at[0];
    for (int i = 1; i < n;i++){
        ct[i] = ct[i - 1] + bt[i];
        tt[i] = ct[i] - at[i]; // Turnaround time = Completion time - Arrival time
        wt[i] = tt[i] - bt[i]; // Waiting time = Turnaround time - Burst time
    }

    // results
    printf("PID\tAT\tBT\tCT\tWT\tTT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], wt[i], tt[i]);
    }

    return 0;
}



int main() {
    fcfs();
    return 0;
}
