#include <stdio.h>
#define MAX 10
int main() {
  int memory[MAX] = {40, 10, 30, 60};
  int n = 4;
  int process[MAX] = {100, 50, 30, 120, 35};
  int m = 5;
  int allocation[MAX] = {-1};
  int i, j, worst_idx;
  for (i = 0; i < m; i++) {
    worst_idx = -1;
    for (j = 0; j < n; j++) {
      if (memory[j] >= process[i]) {
        if (worst_idx == -1 || memory[j] > memory[worst_idx]) {
          worst_idx = j;
        }
      }
    }
    if (worst_idx != -1) {
      allocation[i] = worst_idx;
      memory[worst_idx] -= process[i];
    }
  }
  printf("%10s %10s %15s\n", "Process", "Size", "Block Number");
  for (i = 0; i < m; i++) {
    printf("%10d %10d ", i+1, process[i]);
    if (allocation[i] != -1) {
      printf("%15d\n", allocation[i]+1);
    } else {
      printf("%15s\n", "Not Allocated");
    }
  }
}
