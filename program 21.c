#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define NUM_PHILOSOPHERS 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
pthread_mutex_t forks[NUM_PHILOSOPHERS];
int states[NUM_PHILOSOPHERS];
void print_state() {
    int i;
    printf("Philosophers state: ");
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        if (states[i] == THINKING) {
            printf("T ");
        } else if (states[i] == HUNGRY) {
            printf("H ");
        } else if (states[i] == EATING) {
            printf("E ");
        }
    }
    printf("\n");
}
void *philosopher(void *arg) {
    int id = *(int *)arg;
    int left_fork = id;
    int right_fork = (id + 1) % NUM_PHILOSOPHERS;
	while (1) {
        printf("Philosopher %d is thinking...\n", id);
        sleep(2);
        printf("Philosopher %d is hungry...\n", id);
        states[id] = HUNGRY;
        print_state();
        while (states[(id + NUM_PHILOSOPHERS - 1) % NUM_PHILOSOPHERS] == EATING ||
               states[(id + 1) % NUM_PHILOSOPHERS] == EATING) {
            sleep(1);
        }
        pthread_mutex_lock(&forks[left_fork]);
        pthread_mutex_lock(&forks[right_fork]);
        printf("Philosopher %d is eating...\n", id);
        states[id] = EATING;
        print_state();
        sleep(3);
        pthread_mutex_unlock(&forks[left_fork]);
        pthread_mutex_unlock(&forks[right_fork]);
        states[id] = THINKING;
        printf("Philosopher %d finished eating and is thinking...\n", id);
        print_state();
        sleep(2);
    }
}
int main() {
    int i;
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int ids[NUM_PHILOSOPHERS];
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        ids[i] = i;
    }
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
    }
}
