#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int main() {
    int n = 5;
    int tracks[] = {55, 58, 60, 70, 18};
    int head_pos = 50;
    int i, j, temp, sum = 0;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (abs(tracks[i]-head_pos) > abs(tracks[j]-head_pos)) {
                temp = tracks[i];
                tracks[i] = tracks[j];
                tracks[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++) {
        sum += abs(tracks[i]-head_pos);
        head_pos = tracks[i];
    }
    printf("Average head movement = %d\n", sum/n);
}
