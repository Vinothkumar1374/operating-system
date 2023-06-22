#include <stdio.h>
#include <stdlib.h>
int main() {
    int queue[] = {55, 58, 60, 70, 18};
    int head = 50;
    int total_tracks = 200;
    int direction = 1;
    int i, j, k, seek_time = 0, current_track, next_track, min, max, min_index, max_index;
    int visited[5] = {0};
    int visited_count = 0;
    min = max = queue[0];
    for (i = 1; i < 5; i++) {
        if (queue[i] < min) {
            min = queue[i];
        }
        if (queue[i] > max) {
            max = queue[i];
        }
    }
    current_track = head;
    while (visited_count < 5) {
        min_index = -1;
        max_index = -1;
        for (i = 0; i < 5; i++) {
            if (!visited[i]) {
                if (queue[i] <= current_track && (min_index == -1 || queue[i] > queue[min_index])) {
                    min_index = i;
                }
                if (queue[i] >= current_track && (max_index == -1 || queue[i] < queue[max_index])) {
                    max_index = i;
                }
            }
        }
        if (min_index == -1 && max_index == -1) {
            direction = -direction;
            continue;
        }
        if (direction == 1 && max_index != -1) {
            next_track = queue[max_index];
        } else if (direction == -1 && min_index != -1) {
            next_track = queue[min_index];
        } else if (max_index != -1) {
            next_track = queue[max_index];
        } else {
            next_track = queue[min_index];
        }
        seek_time += abs(next_track - current_track);
        current_track = next_track;
        for (i = 0; i < 5; i++) {
            if (queue[i] == current_track) {
                visited[i] = 1;
                visited_count++;
                break;
            }
        }
    }
    printf("Average head movement: %.2f\n", (float)seek_time/5);
}
