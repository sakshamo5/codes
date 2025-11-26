#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;
void * thread(void * arg){
sem_wait(&mutex);
for(int i=0;i<10;i++){
printf("%d\n",i+1);
sleep(1);
}
sem_post(&mutex);
return NULL;
}

int main(){
sem_init(&mutex,0,1);
pthread_t th1,th2;
pthread_create(&th1,NULL,thread,NULL);
//sleep(2);
pthread_create(&th2, NULL, thread, NULL);
pthread_join(th1,NULL);
pthread_join(th2,NULL);
printf("\nMain thread terminanted\n");
sem_destroy(&mutex);

return 0;
}

