#include <stdio.h>
#define DISK_SIZE 16
#define BLOCK_SIZE 1024
#define NUM_INODES 8
#define FIRST_DATA_BLOCK 8
int disk[DISK_SIZE][BLOCK_SIZE];
void init() {
    int i, j;
    for (i = 0; i < DISK_SIZE; i++) {
        for (j = 0; j < BLOCK_SIZE; j++) {
            disk[i][j] = 0;
        }
    }
}
void printDisk() {
    int i, j;
    for (i = 0; i < DISK_SIZE; i++) {
        printf("Block %d:\n", i);
        for (j = 0; j < BLOCK_SIZE; j++) {
            printf("%d ", disk[i][j]);
        }
        printf("\n");
    }
}
int allocateBlocks(int num_blocks) {
    int i, j, start_block = -1, count = 0;
    for (i = FIRST_DATA_BLOCK; i < DISK_SIZE; i++) {
        if (disk[i][0] == 0) {
            if (start_block == -1) {
                start_block = i;
            }
            count++;
            if (count == num_blocks) {
                for (j = start_block; j < start_block + num_blocks; j++) {
                    disk[j][0] = 1;
                }
                return start_block;
            }
        } else {
            start_block = -1;
            count = 0;
        }
    }
    return -1;
}
int main() {
    init();
    int size, start_block, i, j;
    printf("Enter the file size in KB: ");
    scanf("%d", &size);
    if (size <= 0) {
        printf("Invalid file size\n");
        return 0;
    }
    if (size > DISK_SIZE - NUM_INODES - FIRST_DATA_BLOCK) {
        printf("Not enough space on disk\n");
        return 0;
    }
    int num_blocks = size / BLOCK_SIZE;
    if (size % BLOCK_SIZE != 0) {
        num_blocks++;
    }
    start_block = allocateBlocks(num_blocks);
    if (start_block == -1) {
        printf("Not enough contiguous blocks available\n");
        return 0;
    }
    printf("Allocated blocks: ");
    for (i = start_block; i < start_block + num_blocks; i++) {
        printf("%d ", i);
    }
    printf("\n");
    printf("Disk after allocation:\n");
    printDisk();
    return 0;
}
