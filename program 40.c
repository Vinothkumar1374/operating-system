#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int main() {
    int n = 5;
    int tracks[] = {55, 58, 60, 70, 18};
    int start = 50;
    int head = start;
    int visited[MAX] = {0};
    int total_head_movement = 0;
    int max_track = tracks[0];
    int min_track = tracks[0];
    for (int i = 1; i < n; i++) {
        if (tracks[i] > max_track) {
            max_track = tracks[i];
        }
        if (tracks[i] < min_track) {
            min_track = tracks[i];
        }
    }
    int next_track = start;
    while (next_track <= max_track) {
        if (visited[next_track] == 0) {
            total_head_movement += abs(head - next_track);
            head = next_track;
            visited[head] = 1;
        }
        next_track++;
    }
    next_track = max_track;
    while (next_track >= min_track) {
        if (visited[next_track] == 0) {
            total_head_movement += abs(head - next_track);
            head = next_track;
            visited[head] = 1;
        }
        next_track--;
    }
    printf("Track Positions: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tracks[i]);
    }
    printf("\nStarting Track: %d\n", start);
    printf("Sequence of Tracks Visited: %d ", start);
    for (int i = start + 1; i <= max_track; i++) {
        if (visited[i] == 1) {
            printf("%d ", i);
        }
    }
    for (int i = max_track; i >= min_track; i--) {
        if (visited[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\nTotal Head Movement: %d\n", total_head_movement);
    printf("Average Head Movement: %f\n", (float)total_head_movement / n);
}
