#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define n 5

typedef struct
{
    int pid;
    int at;
    int bt;
    int ct;
    int tt;
    int wt;
    int completed;
} Process;

Process p[n];

void printProcessDetails(Process p[])
{
    printf("PID\tAT\tBT\tCT\tWT\tTT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tt);
    }
}

int random(int a, int b)
{
    return a + rand() % (b - a + 1);
}

void swap(Process *p, Process *q)
{
    Process temp = *p;
    *p = *q;
    *q = temp;
}

int main()
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {

        p[i].pid = i + 1;
        p[i].at = random(0, 10);
        p[i].bt = random(1, 10);
        p[i].ct = 0;
        p[i].tt = 0;
        p[i].wt = 0;
        p[i].completed = 0;
    }

    int completed = 0;
    int time = 0;
    while (completed < n)
    {
        // selecting
        int min_bt = 11;
        int minIdx = -1;
        for (int i = 0; i < n; i++)
        {
            Process process = p[i];
            if (process.at <= time && !process.completed && process.bt < min_bt)
            {
                minIdx = i;
                min_bt = process.bt;
            }
        }
        // decrement bt logic... and completion
        if (minIdx != -1)
        {
            p[minIdx].bt--;
            if(p[minIdx].bt == 0){
                p[minIdx].ct = time;
                p[minIdx].tt = time - p[minIdx].at;
                p[minIdx].wt = p[minIdx].tt - p[minIdx].bt;
                p[minIdx].completed = 1;
                completed++;
            }
        }

        time++;
    } // while end

    printProcessDetails(p);
}