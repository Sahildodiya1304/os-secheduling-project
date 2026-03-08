#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INF 999999

FILE *fp;

int main() {

    fp = fopen("gantt_data.txt","w");

    int n;

    // Validate number of processes
    do {
        printf("Enter number of processes (1-100): ");
        scanf("%d", &n);

        if(n <= 0 || n > MAX)
            printf("Invalid! Enter value between 1 and 100.\n");

    } while(n <= 0 || n > MAX);

    int pid[MAX], isCompleted[MAX];
    float at[MAX], bt[MAX], ct[MAX], tat[MAX], wt[MAX];

    // Input section
    for(int i = 0; i < n; i++) {

        pid[i] = i + 1;
        isCompleted[i] = 0;

        printf("\nProcess %d\n", pid[i]);

        // Arrival Time validation
        do {
            printf("Arrival Time (>=0): ");
            scanf("%f", &at[i]);

            if(at[i] < 0)
                printf("Arrival time cannot be negative!\n");

        } while(at[i] < 0);

        // Burst Time validation
        do {
            printf("Burst Time (>0): ");
            scanf("%f", &bt[i]);

            if(bt[i] <= 0)
                printf("Burst time must be greater than 0!\n");

        } while(bt[i] <= 0);
    }

    float currentTime = 0;
    int completed = 0;
    float totalWT = 0, totalTAT = 0;

    printf("\n========== SJF Execution Log ==========\n");

    while(completed < n) {

        int index = -1;
        float minBT = INF;

        // Find shortest job among arrived processes
        for(int i = 0; i < n; i++) {

            if(at[i] <= currentTime && isCompleted[i] == 0) {

                if(bt[i] < minBT) {
                    minBT = bt[i];
                    index = i;
                }

                // Tie-breaking rule
                else if(bt[i] == minBT) {
                    if(at[i] < at[index])
                        index = i;
                }
            }
        }

        // If process found
        if(index != -1) {

            float startTime = currentTime;

            ct[index] = currentTime + bt[index];
            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];

            currentTime = ct[index];
            isCompleted[index] = 1;
            completed++;

            printf("Process P%d executed from %.2f to %.2f\n",
                   pid[index], startTime, ct[index]);

            // Write to Gantt file
            fprintf(fp,"P%d %.2f %.2f\n", pid[index], startTime, bt[index]);

            totalWT += wt[index];
            totalTAT += tat[index];
        }
        else {

            // CPU Idle Condition

            float nextArrival = INF;

            for(int i = 0; i < n; i++) {
                if(isCompleted[i] == 0 && at[i] > currentTime) {
                    if(at[i] < nextArrival)
                        nextArrival = at[i];
                }
            }

            printf("CPU Idle from %.2f to %.2f\n",
                   currentTime, nextArrival);

            // Write idle to file
            fprintf(fp,"IDLE %.2f %.2f\n", currentTime, nextArrival-currentTime);

            currentTime = nextArrival;
        }
    }

    printf("\n--------------------------------------------------------------\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    printf("--------------------------------------------------------------\n");

    for(int i = 0; i < n; i++) {

        printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("--------------------------------------------------------------\n");
    printf("Average Waiting Time = %.2f\n", totalWT/n);
    printf("Average Turnaround Time = %.2f\n", totalTAT/n);

    fclose(fp);
    system("python visualize.py || python3 visualize.py");
    return 0;
}