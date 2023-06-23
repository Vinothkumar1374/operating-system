#include <stdio.h>
#include <stdlib.h>
#define NUM_PARTITIONS 4
#define MAX_PROCESS_SIZE 120
int partitions[NUM_PARTITIONS] = {40, 10, 30, 60};
int first_fit(int process_size) {
  for (int i = 0; i < NUM_PARTITIONS; i++) {
    if (partitions[i] >= process_size) {
      partitions[i] -= process_size;
      return i;
    }
  }
  return -1;
}
void print_partitions() {
  printf("Memory partitions: ");
  for (int i = 0; i < NUM_PARTITIONS; i++) {
    printf("%d KB ", partitions[i]);
  }
  printf("\n");
}
int main() {
  int process_sizes[5] = {100, 50, 30, 120, 35};
  for (int i = 0; i < 5; i++) {
    int index = first_fit(process_sizes[i]);
    if (index == -1) {
      printf("Process of size %d KB cannot be allocated.\n", process_sizes[i]);
    } else {
      printf("Process of size %d KB is allocated to partition %d.\n", process_sizes[i], index);
    }
    print_partitions();
  }
}
