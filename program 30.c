#include <stdio.h>
#include <pthread.h>
void *print_even(void *arg) {
    int i;
    for (i = 0; i <= 10; i += 2) {
        printf("%d ", i);
    }
    return NULL;
}
void *print_odd(void *arg) {
    int i;
    for (i = 1; i <= 10; i += 2) {
        printf("%d ", i);
    }
    return NULL;
}
int main() {
    pthread_t even_thread, odd_thread;
    if (pthread_create(&even_thread, NULL, print_even, NULL)) {
        printf("Error creating even thread!\n");
        return 1;
    }
    if (pthread_create(&odd_thread, NULL, print_odd, NULL)) {
        printf("Error creating odd thread!\n");
        return 1;
    }
    if (pthread_join(even_thread, NULL)) {
        printf("Error joining even thread!\n");
        return 1;
    }
    if (pthread_join(odd_thread, NULL)) {
        printf("Error joining odd thread!\n");
        return 1;
    }
}
