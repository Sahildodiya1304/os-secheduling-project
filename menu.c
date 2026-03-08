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
                system("./fcfs 2>/dev/null || fcfs");
                break;

            case 2:
                system("./sjf 2>/dev/null || sjf");
                break;

            case 3:
                system("./srtf 2>/dev/null || srtf");
                break;

            case 4:
                system("./rr 2>/dev/null || rr");
                break;

            case 5:
                system("./priority 2>/dev/null || priority");
                break;
            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }


    return 0;
}