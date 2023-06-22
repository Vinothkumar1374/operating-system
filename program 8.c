#include <stdio.h>
#include <stdlib.h>
#define MAX_TRACKS 1000
int main() {
 int tracks[MAX_TRACKS];
 int n, head_pos, total_distance;
 printf("Enter number of tracks: ");
 scanf("%d", &n);
printf("Enter track positions: ");
 for (int i = 0; i < n; i++) {
 scanf("%d", &tracks[i]);
 }
printf("Enter initial head position: ");
 scanf("%d", &head_pos);
 total_distance = 0;
 for (int i = 0; i < n; i++) {
 total_distance += abs(tracks[i] - head_pos);
 head_pos = tracks[i];
 }
 printf("Total head movement: %d\n", total_distance);
 printf("Average head movement: %.2f\n", (float) total_distance / n);
return 0;
}
