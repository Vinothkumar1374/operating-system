#include <stdio.h>
#define MAX 100
int main() {
    int n = 8;
    int ref_seq[] = {4, 1, 2, 4, 3, 2, 1, 5};
    int m = 3;
    int frames[m];
    int i, j, k, pos, max, page_faults = 0, flag;
    for (i = 0; i < m; i++) {
        frames[i] = -1;
    }
    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < m; j++) {
            if (ref_seq[i] == frames[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            page_faults++;
            max = -1;
            for (j = 0; j < m; j++) {
                for (k = i+1; k < n; k++) {
                    if (ref_seq[k] == frames[j]) {
                        if (k > max) {
                            max = k;
                            pos = j;
                        }
                        break;
                    }
                }
                if (k == n && frames[j] == -1) {
                    pos = j;
                    break;
                }
            }
            frames[pos] = ref_seq[i];
        }
        for (j = 0; j < m; j++) {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }
    printf("Number of page faults = %d\n", page_faults);
}
