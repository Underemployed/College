#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 10

int random(int a, int b)
{
    int r = a +  rand() % (b - a + 1);

    return r;
}

void swap(int *p, int *q){
    int temp = *q;
    *q = *p;
    *p = temp;
}

int main()
{
    srand(time(NULL));
    // printf("%d", random(1, 3));
    int pid[n];
    int at[n];
    int bt[n];
    int ct[n] = {0};
    int tt[n] = {0};
    int wt[n] = {0};

    for (int i = 0; i < n; i++){
        at[i] = random(0, n);
        bt[i] = random(1, n);
        pid[i] = i;
    }

    // sorting(bubble sort) my version
    int count = 0;
    int notsorted = 1;
    while(notsorted){
        notsorted = 0;
        for (int i = 0; i < n - count - 1;i++){
            int j = i + 1;
            if(at[i] > at[j]){
                swap(&at[i], &at[j]);
                swap(&bt[i], &bt[j]);
                swap(&pid[i], &pid[j]);
                notsorted = 1;
            }
        }
        count++;
    }


    printf("\n==================\n\n");

    ct[0] = at[0] + bt[0];
    tt[0] = ct[0] - at[0];
    wt[0] = 0;
    int time = ct[0];
    for (int i = 1; i < n;i++){
        // skip time if new process is yet to come
        if(at[i] >=time){
            time = at[i];
        }

        ct[i] = time + bt[i];
        tt[i] = ct[i] - at[i];
        wt[i] = tt[i] - bt[i];
        // time after completing current process
        time = ct[i];
    }

    // results
    printf("PID\tAT\tBT\tCT\tWT\tTT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], wt[i], tt[i]);
    }
}

