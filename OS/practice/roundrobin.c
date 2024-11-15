#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 5
# define quant 3
typedef struct {
    int pid;
    int at;
    int bt;
    int ct;
    int tt;
    int wt;
    int rt;
    int completed;
} Process;
Process p[n];

int random(int a,int b){
    return a + rand() % (b - a + 1);
}


void printDetails(){
    printf("PID\trt\tBT\tCT\tTT\tWT\n");
    for (int i = 0; i < n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].rt, p[i].bt, p[i].ct, p[i].tt, p[i].wt);
    }
    printf("\n=====================\n");
}


void main(){
    for (int i = 0; i < n; i++){
        p[i].at = 0;
        p[i].bt = random(1, n);
        p[i].rt = p[i].bt;
        p[i].ct = 0;

        p[i].pid = i;
        p[i].completed = 0;
        p[i].tt = 0;
        p[i].wt = 0;
    }

    printDetails();
    int completed = 0;
    int i = 0;
    int time = 0;
    while(completed < n){
        if(p[i].rt > 0){
            if (p[i].rt > quant){
                p[i].rt = p[i].rt - quant;
                time += quant;
            }else{
                time = time + p[i].rt;

                p[i].ct = time;
                p[i].rt = 0;

                p[i].tt = p[i].ct - p[i].at;
                p[i].wt = p[i].tt - p[i].bt;
                completed++;
            }
        }

        
        i = (i+1) % n;
    }
    printDetails();
}