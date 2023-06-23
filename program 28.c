#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define MAX_SIZE 1000
int main() {
    char filename[50];
    char data[MAX_SIZE];
    int fd, n;
	printf("Enter the filename: ");
    scanf("%s", filename);
    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (fd == -1) {
        printf("Error creating the file!\n");
        exit(1);
    }
    printf("Enter the data to write to the file: ");
    scanf(" %[^\n]", data);
    n = write(fd, data, sizeof(data));
    if (n == -1) {
        printf("Error writing to the file!\n");
        exit(1);
    }
    close(fd);
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening the file for reading!\n");
        exit(1);
    }
    n = read(fd, data, sizeof(data));
    if (n == -1) {
        printf("Error reading from the file!\n");
        exit(1);
    }
    printf("Data read from the file: %s\n", data);
    close(fd);
}
