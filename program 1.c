#include <stdio.h>

int main() {

    int claim[4][3] = {{3, 2, 2}, {6, 1, 3}, {3, 1, 4}, {4, 2, 2}};
    int allocation[4][3] = {{1, 0, 0}, {6, 1, 2}, {2, 1, 1}, {0, 0, 2}};
    int resource[3] = {9, 3, 6};
    int available[3] = {0, 0, 0};

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 4; i++) {
            available[j] += allocation[i][j];
        }
        available[j] = resource[j] - available[j];
    }


    int finish[4] = {0, 0, 0, 0};
    int safe_sequence[4];
    int num_finished = 0;

    while (num_finished < 4) {
        int safe_found = 0;

        for (int i = 0; i < 4; i++) {
            if (!finish[i]) {
                int can_finish = 1;
                for (int j = 0; j < 3; j++) {
                    if (claim[i][j] - allocation[i][j] > available[j]) {
                        can_finish = 0;
                        break;
                    }
                }
                if (can_finish) {

                    safe_sequence[num_finished] = i;
                    num_finished++;
                    finish[i] = 1;
                    for (int j = 0; j < 3; j++) {
                        available[j] += allocation[i][j];
                    }
                    safe_found = 1;
                }
            }
        }


        if (!safe_found) {
            break;
        }
    }

    if (num_finished == 4) {

        printf("Safe sequence: ");
        for (int i = 0; i < 4; i++) {
            printf("%d ", safe_sequence[i]);
        }
        printf("\nThe system is in a safe state.\n");
    } else {
        printf("The system is in an unsafe state.\n");
    }

    return 0;
}
