//Reader Writer
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> // For usleep function

sem_t mutex;
sem_t wrt;
int readcount = 0;

void *reader(void *arg) {
    int thread_id = *(int *)arg;
    sem_wait(&mutex);
    readcount++;
    if (readcount == 1) {
        sem_wait(&wrt);
    }
    sem_post(&mutex);
    printf("Reader %d enters.\n", thread_id);
    // Simulate reading operation
    usleep(1000);
    sem_wait(&mutex);
    readcount--;
    if (readcount == 0) {
        sem_post(&wrt);
    }
    sem_post(&mutex);
    printf("Reader %d leaves.\n", thread_id);
    pthread_exit(NULL);
}

void *writer(void *arg) {
    int thread_id = *(int *)arg;
    sem_wait(&wrt);
    printf("Writer %d enters.\n", thread_id);
    // Simulate writing operation
    usleep(2000);
    sem_post(&wrt);
    printf("Writer %d leaves.\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    int num_readers = 7;
    int num_writers = 9;
    pthread_t reader_threads[num_readers];
    pthread_t writer_threads[num_writers];
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);
    int reader_ids[num_readers];
    int writer_ids[num_writers];
    int i;
    for (i = 0; i < num_readers; i++) {
        reader_ids[i] = i;
        pthread_create(&reader_threads[i], NULL, reader, &reader_ids[i]);
    }
    for (i = 0; i < num_writers; i++) {
        writer_ids[i] = i;
        pthread_create(&writer_threads[i], NULL, writer, &writer_ids[i]);
    }
    for (i = 0; i < num_readers; i++) {
        pthread_join(reader_threads[i], NULL);
    }
    for (i = 0; i < num_writers; i++) {
        pthread_join(writer_threads[i], NULL);
    }
    sem_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}
