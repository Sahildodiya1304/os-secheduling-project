#include <stdio.h>
#include <stdlib.h>

int main() {

    int choice;



        printf("\nCPU Scheduling Simulator\n");
        printf("------------------------\n");
        printf("1. FCFS\n");
        printf("2. SJF\n");
        printf("3. SRTF\n");
        printf("4. Round Robin\n");
        printf("5. Priority\n");
        printf("6. Exit\n");

        printf("\nSelect Algorithm: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                system("fcfs");
                break;

            case 2:
                system("SJF");
                break;

            case 3:
                system("SRTF");
                break;

            case 4:
                system("RR");
                break;

            case 5:
                system("PRIORITY");
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }


    return 0;
}