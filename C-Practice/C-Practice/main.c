#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QUEUE_SIZE 100

struct Queue {
    int data[MAX_QUEUE_SIZE];
    int front, rear;
};

void init_queue(struct Queue* q)
{
    q->front = -1;
    q->rear = -1;
}

int is_full(struct Queue* q) {
    return q->rear == MAX_QUEUE_SIZE - 1;
}

int is_empty(struct Queue* q) {
    return q->rear == - 1;
}

void enqueue(struct Queue* q, int item) {
    if(is_full(q)) printf("is_full");
    else {
        q->data[++q->rear] = item;
    }
}

int dequeue(struct Queue* q) {
    if(is_empty(q)){
        printf("is_empty");
        return -99999;
    } else {
        return q->data[++q->front];
    }
}

int main(void) {
    struct Queue q;
    int n, a;
    
    init_queue(&q);
    printf("넣고싶은 값의 개수 : ");
    scanf("%d", &n);
    
    printf("넣은 값 : ");
    
    for (int i = 0; i < n; i++) {
        a = rand() % 100;
        printf("%d ", a);
        enqueue(&q, a);
    }
    
    printf("\n출력한 값 : ");

    for(int i = 0; i < n; i++){
        printf("%d ", dequeue(&q));
    }
    printf("\n");
    return 0;
}
