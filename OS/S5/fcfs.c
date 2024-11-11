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



int fcfs() {
    int at[n], pid[n], bt[n], i;
    for (i = 0; i < n; i++) {
        at[i] = random(0, n);  
        bt[i] = random(1, n);   
        pid[i] = i;
    }

    for (int i = 0; i < n; i++)

        printf("PID\tAT\tBT\n");
    for (i = 0; i < 10; i++) {
        printf("%d\t%d\t%d\n", pid[i], at[i], bt[i]);
    }

    return 0;
}

int main() {
    fcfs();
    return 0;
}
