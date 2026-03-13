#include <stdio.h>
#include <stdlib.h>

int main() {

    int choice;

    while(1) {

        printf("\nCPU Scheduling Simulator\n");
        printf("------------------------\n");
        printf("1. Enter Process Data\n");
        printf("2. FCFS\n");
        printf("3. SJF\n");
        printf("4. SRTF\n");
        printf("5. Round Robin\n");
        printf("6. Priority\n");
        printf("7. Compare Algorithms\n");
        printf("8. Exit\n");

        printf("\nSelect Option: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                system("input || ./input");
                break;

            case 2:
                system("fcfs || ./fcfs");
                break;

            case 3:
                system("sjf || ./sjf");
                break;

            case 4:
                system("srtf || ./srtf");
                break;

            case 5:
                system("rr || ./rr");
                break;

            case 6:
                system("priority || ./priority");
                break;

            case 7:

                fopen("comparison_data.txt","w");

                system("fcfs || ./fcfs");
                system("sjf || ./sjf");
                system("srtf || ./srtf");
                system("rr || ./rr");
                system("priority || ./priority");

                system("python compare.py || python3 compare.py");

                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}