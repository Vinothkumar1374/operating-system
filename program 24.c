#include <stdio.h>
#include <stdlib.h>
#define BLOCK_SIZE 8192
#define BLOCK_PTR_SIZE 4
#define DIRECT_BLOCK_COUNT 12
#define INDIRECT_BLOCK_PTRS_PER_BLOCK (BLOCK_SIZE / BLOCK_PTR_SIZE)
#define DOUBLE_INDIRECT_BLOCK_PTRS_PER_BLOCK (BLOCK_SIZE / BLOCK_PTR_SIZE)
#define TRIPLE_INDIRECT_BLOCK_PTRS_PER_BLOCK (BLOCK_SIZE / BLOCK_PTR_SIZE)
long long get_max_file_size() {
    long long max_file_size = 0;
    int direct_blocks_used = 0, indirect_blocks_used = 0, double_indirect_blocks_used = 0, triple_indirect_blocks_used = 0;
    direct_blocks_used = DIRECT_BLOCK_COUNT;
    indirect_blocks_used = INDIRECT_BLOCK_PTRS_PER_BLOCK;
    double_indirect_blocks_used = INDIRECT_BLOCK_PTRS_PER_BLOCK * INDIRECT_BLOCK_PTRS_PER_BLOCK;
    triple_indirect_blocks_used = INDIRECT_BLOCK_PTRS_PER_BLOCK * INDIRECT_BLOCK_PTRS_PER_BLOCK * INDIRECT_BLOCK_PTRS_PER_BLOCK;
    max_file_size = (long long)direct_blocks_used * BLOCK_SIZE + (long long)indirect_blocks_used * BLOCK_SIZE + (long long)double_indirect_blocks_used * BLOCK_SIZE + (long long)triple_indirect_blocks_used * BLOCK_SIZE;
	return max_file_size;
}
int main() {
    long long max_file_size = get_max_file_size();
    printf("Maximum file size that can be stored in the given file system: %lld bytes\n", max_file_size);

}
