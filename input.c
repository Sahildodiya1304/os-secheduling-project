#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {

    FILE *fp;
    int n;
    float at, bt;
    int pr, tq;

    fp = fopen("process_data.txt","w");

    if(fp == NULL){
        printf("Error opening file!\n");
        return 1;
    }

    // Number of processes validation
    do{
        printf("Enter number of processes (1-100): ");
        scanf("%d",&n);

        if(n <= 0 || n > MAX)
            printf("Invalid! Enter between 1 and 100.\n");

    }while(n <= 0 || n > MAX);

    fprintf(fp,"%d\n",n);

    for(int i=0;i<n;i++){

        printf("\nProcess %d\n",i+1);

        // Arrival Time validation
        do{
            printf("Arrival Time (>=0): ");
            scanf("%f",&at);

            if(at < 0)
                printf("Arrival time cannot be negative!\n");

        }while(at < 0);

        // Burst Time validation
        do{
            printf("Burst Time (>0): ");
            scanf("%f",&bt);

            if(bt <= 0)
                printf("Burst time must be greater than 0!\n");

        }while(bt <= 0);

        printf("Priority (smaller number = higher priority): ");
        scanf("%d",&pr);

        fprintf(fp,"%f %f %d\n",at,bt,pr);
    }

    // Time Quantum validation
    do{
        printf("\nEnter Time Quantum for Round Robin (>0): ");
        scanf("%d",&tq);

        if(tq <= 0)
            printf("Time Quantum must be greater than 0!\n");

    }while(tq <= 0);

    fprintf(fp,"%d\n",tq);

    fclose(fp);

    printf("\nProcess data saved successfully to process_data.txt\n");

    return 0;
}