#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int read_count = 0;
int shared_data = 10;  

sem_t mutex;      
sem_t rw_mutex;   

void* reader(void* arg) {
    sem_wait(&mutex);
    read_count++;
    if (read_count == 1) {
        sem_wait(&rw_mutex);  
    }
    sem_post(&mutex);

    printf("Reader is reading: %d\n", shared_data);
    sleep(1);

    sem_wait(&mutex);
    read_count--;
    if (read_count == 0) {
        sem_post(&rw_mutex);
    }
    sem_post(&mutex);

    return NULL;
}

void* writer(void* arg) {
    sem_wait(&rw_mutex);

    shared_data += 10;  
    printf("Writer is writing: %d\n", shared_data);
    sleep(1);  

    sem_post(&rw_mutex);  

    return NULL;
}

int main() {
    pthread_t r_thread, w_thread;
	printf("Current value is : %d\n", shared_data);
    sem_init(&mutex, 0, 1);
    sem_init(&rw_mutex, 0, 1);

    pthread_create(&r_thread, NULL, reader, NULL);
    pthread_create(&w_thread, NULL, writer, NULL);
	pthread_create(&r_thread, NULL, reader, NULL);
    pthread_join(r_thread, NULL);
    pthread_join(w_thread, NULL);

    sem_destroy(&mutex);
    sem_destroy(&rw_mutex);

    return 0;
}
