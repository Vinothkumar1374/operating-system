#include <stdio.h>
#define N_PROCESSES 5
#define N_RESOURCES 3
int main()
{
 int allocation[N_PROCESSES][N_RESOURCES] = {{1, 1, 2}, {2, 1, 2}, {3, 0, 1}, {0, 2, 0}, {1,
1, 2}};
 int max[N_PROCESSES][N_RESOURCES] = {{5, 4, 4}, {4, 3, 3}, {9, 1, 3}, {8, 6, 4}, {2, 2, 3}};
 int available[N_RESOURCES] = {3, 3, 2};
 int need[N_PROCESSES][N_RESOURCES];
 int i, j;
 for(i=0; i<N_PROCESSES; i++)
 {
 for(j=0; j<N_RESOURCES; j++)
 {
 need[i][j] = max[i][j] - allocation[i][j];
 }
 }
 printf("Need matrix:\n");
 printf(" A B C\n");
 for(i=0; i<N_PROCESSES; i++)
 {
 printf("P%d ", i);
 for(j=0; j<N_RESOURCES; j++)
 {
 printf("%2d ", need[i][j]);
 }
 printf("\n");
 }
 return 0;
}
