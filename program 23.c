#include <stdio.h>
#include <stdlib.h>
#define MAX_TRACKS 100
int abs_diff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}
int main() {
    int num_tracks, track_pos[MAX_TRACKS], head_pos, i, j, total_distance = 0;
    printf("Enter the number of tracks: ");
    scanf("%d", &num_tracks);
    printf("Enter the track positions: ");
    for (i = 0; i < num_tracks; i++) {
        scanf("%d", &track_pos[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head_pos);
    for (i = 0; i < num_tracks-1; i++) {
        for (j = i+1; j < num_tracks; j++) {
            if (track_pos[i] > track_pos[j]) {
                int temp = track_pos[i];
                track_pos[i] = track_pos[j];
                track_pos[j] = temp;
            }
        }
    }
    for (i = 0; i < num_tracks; i++) {
        if (track_pos[i] >= head_pos) {
            break;
        }
    }
    for (j = i; j < num_tracks; j++) {
        total_distance += abs_diff(head_pos, track_pos[j]);
        head_pos = track_pos[j];
    }
    for (j = i-1; j >= 0; j--) {
        total_distance += abs_diff(head_pos, track_pos[j]);
        head_pos = track_pos[j];
    }
    printf("Total distance traveled: %d\n", total_distance);
    printf("Average head movement: %.2f\n", (float)total_distance / num_tracks);
}
