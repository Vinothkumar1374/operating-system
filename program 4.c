#include <stdio.h>
int main() {
    int memory[] = {300, 600, 350, 200, 750, 125};
    int n = sizeof(memory)/sizeof(memory[0]);
    int process[] = {115, 500, 358, 200, 375};
	int m = sizeof(process)/sizeof(process[0]);
    int allocation[m];
    for (int i = 0; i < m; i++)
        allocation[i] = -1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (memory[j] >= process[i]) {
                allocation[i] = j;
                memory[j] -= process[i];
                break;
            }
        }
    }
    printf("Process No.\tProcess Size\tAllocated Block No.\n");
    for (int i = 0; i < m; i++) {
        printf("%d\t\t%d KB\t\t", i+1, process[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i]+1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
