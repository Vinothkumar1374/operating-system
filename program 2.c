#include <stdio.h>

int main() {
    int n = 8;
    int frames = 3;s
    int pages[n];
    int page_faults = 0;
    int buffer[frames];
    int buffer_index = 0;

    // initialize page reference array
    pages[0] = 4;
    pages[1] = 1;
    pages[2] = 2;
    pages[3] = 4;
    pages[4] = 3;
    pages[5] = 2;
    pages[6] = 1;
    pages[7] = 5;

    // initialize buffer array to -1
    for (int i = 0; i < frames; i++) {
        buffer[i] = -1;
    }


    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;


        for (int j = 0; j < frames; j++) {
            if (buffer[j] == page) {
                found = 1;
                break;
            }
        }


        if (!found) {
            buffer[buffer_index] = page;
            buffer_index = (buffer_index + 1) % frames;
            page_faults++;
        }


        printf("Buffer: ");
        for (int j = 0; j < frames; j++) {
            printf("%d ", buffer[j]);
        }
        printf("\n");
    }


    printf("Total Page Faults: %d\n", page_faults);

    return 0;
}
